/*
** EPITECH PROJECT, 2022
** ft_calc_dir.c
** File description:
** Function to calc direction.
*/

#include "my.h"

sfVector2f calc_dir_two(float stotck, sfVector2i dir)
{
    sfVector2f final;
    final.x = 8;
    final.y = 8 / stotck;
    if (dir.x - 960 < 0 && dir.y - 560) {
        final.x = final.x * (-1);
        final.y = final.y * (-1);
    } else if (dir.x - 960 < 0)
        final.x = final.x * (-1);
    return final;
}

sfVector2f calc_dir(sfVector2i dir, sfSprite *sprite)
{
    sfVector2f spri = sfSprite_getPosition(sprite);
    sfVector2f final;
    final.x = dir.x - 960;
    final.y = dir.y - 560;
    float stotck = final.x / final.y;
    if (stotck < 1 && stotck > -1) {
        final.y = 8;
        final.x = 8 * stotck;
        if (dir.y - 560 < 0) {
            final.y = final.y * (-1);
            final.x = final.x * (-1);
        }
    } else
        final = calc_dir_two(stotck, dir);
    return final;
}

void dir_dague(game_t *g, add_attack_t *element, int nb)
{
    if (nb == 1)
        element->dir = set_pos(g->start.perso.speed, 0);
    if (nb == 2) {
        element->dir = set_pos(0, g->start.perso.speed);
        sfSprite_rotate(element->sprite.sprite, 90);
    }
    if (nb == 3) {
        element->dir = set_pos(-g->start.perso.speed, 0);
        sfSprite_rotate(element->sprite.sprite, 180);
    }
    if (nb == 4) {
        element->dir = set_pos(0, -g->start.perso.speed);
        sfSprite_rotate(element->sprite.sprite, 270);
    }
    if (nb == 5) {
        element->dir = set_pos(g->start.perso.speed, 0);
    }
}
