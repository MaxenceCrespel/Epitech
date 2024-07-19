/*
** EPITECH PROJECT, 2022
** ft_move_map.c
** File description:
** Function to move all in the map.
*/

#include "my.h"

void move_monster_map(add_monster_t *mons, sfVector2f move)
{
    add_monster_t *tmp = mons;

    while (tmp) {
        sfSprite_move(tmp->sprite.sprite, move);
        tmp = tmp->next;
    }
}

void move_text_map(add_text_t *mons, sfVector2f move)
{
    add_text_t *tmp = mons;

    while (tmp) {
        sfText_move(tmp->damage.text, move);
        tmp = tmp->next;
    }
}

void move_cryst_map(add_crist_t *mons, sfVector2f move)
{
    add_crist_t *tmp = mons;

    while (tmp) {
        sfSprite_move(tmp->cryst.sprite, move);
        tmp = tmp->next;
    }
}

void move_item_map(game_t *g, sfVector2f move)
{
    for (int i = 0; i < 6; i++) {
        if (g->item_l[i].status == 1)
            sfSprite_move(g->item_l[i].img.sprite, move);
    }
}

void change_pos_game(game_t *g, sfVector2f move)
{
    g->start.pos.x -= move.x;
    g->start.pos.y -= move.y;
    sfText_setString(g->start.t_pos_x.text, my_itoa((int)g->start.pos.x));
    sfText_setString(g->start.t_pos_y.text, my_itoa((int)g->start.pos.y));
}
