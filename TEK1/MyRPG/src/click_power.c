/*
** EPITECH PROJECT, 2022
** click_power.c
** File description:
** Click power.
*/

#include "my.h"

void click_power2(game_t *g)
{
    if (verrif_button_click(g, g->option.quit.sprite)) {
        press_buttons(g, g->menu.quit.sprite, 67, -1);
        sfRenderWindow_close(g->window);
    }
    if (verrif_button_click(g, g->option.back.sprite)) {
        g->power_up.display = -1;
        press_buttons(g, g->option.back.sprite, 67, 0);
    }
}

void click_power(game_t *g)
{
    click_power2(g);
    int touch = 0;
    for (int i = 0; i < 11; i++) {
        if (verrif_button_click(g, g->power_up.list[i].bg.sprite)) {
            g->power_up.display = i;
            copy_power_select(g, i);
            touch++;
        }
        if (g->power_up.display == i
        && verrif_button_click(g, g->power_up.buy.sprite)
        && g->power_up.list[i].have_nb != 3) {
            press_buttons(g, g->power_up.buy.sprite, 67, -1);
            augment_power(g, i);
        }
    }
}
