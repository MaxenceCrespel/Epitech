/*
** EPITECH PROJECT, 2022
** create tree
** File description:
** tree
*/

#include "my.h"

void display_arbre(game_t *g)
{
    for (int i = 0; i < 160; i++)
        sfRenderWindow_drawSprite(g->window, g->start.tree[i].sprite, NULL);
}

void move_tree(game_t *g, sfVector2f move)
{
    for (int i = 0; i < 160; i++)
        sfSprite_move(g->start.tree[i].sprite, move);
}

int touch_tree(game_t *g, sfVector2f move)
{
    sfFloatRect rect;
    sfFloatRect img = {900 - move.x, 520 - move.y, 40, 40};
    for (int i = 0; i < 160; i++) {
        rect = sfSprite_getGlobalBounds(g->start.tree[i].sprite);
        rect.height -= 48;
        if (sfFloatRect_intersects(&img, &rect, NULL)) {
            return 1;
        }
    }
    return 0;
}

my_sprite_t *create_tree(game_t *g)
{
    my_sprite_t *list = malloc(sizeof(my_sprite_t) * 160);
    sfTexture *bg = sfTexture_createFromFile("assets/img/tenemies.png", NULL);
    sfIntRect *rect = malloc(sizeof(sfIntRect) * 4);
    rect[0] = pos_rect(632, 149, 27, 60);
    rect[1] = pos_rect(182, 306, 33, 62);
    rect[2] = pos_rect(567, 106, 30, 61);
    rect[3] = pos_rect(1354, 52, 34, 63);
    for (int i = 0; i < 160; i++) {
        list[i] = set_sprite_rect(bg, random_pos_item(),
        set_pos(3, 3), rect[rand() % 4]);
    }
    return list;
}
