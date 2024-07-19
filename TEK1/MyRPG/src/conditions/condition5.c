/*
** EPITECH PROJECT, 2022
** condition5
** File description:
** rpg
*/

#include "my.h"

sfVector2f calc_path_monster2(float speed, float stotck,
sfVector2f pos_actual)
{
    sfVector2f path;
    path.x = speed;
    path.y = speed / stotck;
    if (pos_actual.x - 960 > 0 && pos_actual.y - 560) {
        path.x = path.x * (-1);
        path.y = path.y * (-1);
    } else if (pos_actual.x - 960 > 0)
        path.x = path.x * (-1);
    return path;
}

sfVector2f calc_path_monster(game_t *g, sfSprite *actual, float speed)
{
    sfVector2f pos_actual = sfSprite_getPosition(actual);
    sfVector2f path;
    path.x = 930 - pos_actual.x;
    path.y = 530 - pos_actual.y;
    float stotck = path.x / path.y;
    if (stotck < 1 && stotck > -1) {
        path.y = speed;
        path.x = speed * stotck;
        if (pos_actual.y - 560 > 0) {
            path.y = path.y * (-1);
            path.x = path.x * (-1);
        }
    } else
        path = calc_path_monster2(speed, stotck, pos_actual);
    return path;
}

int monst_can_move(game_t *g, add_monster_t *tmp)
{
    sfVector2f pos_actual = sfSprite_getPosition(tmp->sprite.sprite);
    pos_actual.x += 60;
    pos_actual.y += 20;
    sfFloatRect rect = sfSprite_getGlobalBounds(g->start.perso.sprite.sprite);
    rect.width += 50;
    rect.height += 50;
    if (sfFloatRect_contains(&rect, pos_actual.x, pos_actual.y))
        return 0;
    return 1;
}

int get_rotate(int nb)
{
    if (nb == 0)
        return (-5);
    if (nb == 1)
        return 0;
    if (nb == 2)
        return 5;
    if (nb == 3)
        return 0;
}
