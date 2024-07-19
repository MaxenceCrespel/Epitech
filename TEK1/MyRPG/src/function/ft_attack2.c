/*
** EPITECH PROJECT, 2022
** ft_attack2.c
** File description:
** Function to attack.
*/

#include "my.h"

void attack_un(game_t *g)
{
    if (g->start.attack[1].have == 1) {
        g->start.d_attack = new_attack(g, g->start.attack[1].status,
        g->start.d_attack);
        g->start.d_attack->damage += (g->start.attack[1].lvl - 1) * 3;
        if (g->start.attack[1].lvl >= 3 && g->start.attack[1].status == 2)
            g->start.d_attack = new_knife(g, g->start.attack[1].status,
            g->start.d_attack);
        if (g->start.attack[1].lvl >= 3 && g->start.attack[1].status == 0)
            g->start.d_attack = new_fouet(g, g->start.attack[1].status,
            g->start.d_attack);
        sfClock_restart(g->start.attack[1].clock);
        sound_attack(g, g->start.attack[1].status);
    }
}

void attack_deux(game_t *g)
{
    if (g->start.attack[2].have == 1) {
        g->start.d_attack = new_attack(g, g->start.attack[2].status,
        g->start.d_attack);
        g->start.d_attack->damage += (g->start.attack[2].lvl - 1) * 3;
        if (g->start.attack[2].lvl >= 3 && g->start.attack[2].status == 2)
            g->start.d_attack = new_knife(g, g->start.attack[2].status,
            g->start.d_attack);
        if (g->start.attack[2].lvl >= 3 && g->start.attack[2].status == 0)
            g->start.d_attack = new_fouet(g, g->start.attack[2].status,
            g->start.d_attack);
        sfClock_restart(g->start.attack[2].clock);
        sound_attack(g, g->start.attack[2].status);
    }
}

void remove_list_item(game_t *g)
{
    for (int i = 0; i < 6; i++) {
        if (g->start.item[i].img.sprite) {
            g->start.item[i].have = 0;
            g->start.item[i].img.sprite = NULL;
        }
    }
}

void buy_perso(game_t *g)
{
    if (g->save.i_or >= 300) {
        g->save.i_or -= 300;
        g->save.perso[g->menu.select] = 1;
        sfText_setString(g->save.t_or.text, my_itoa(g->save.i_or));
    }
}
