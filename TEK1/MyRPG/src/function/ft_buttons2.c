/*
** EPITECH PROJECT, 2022
** ft_buttons2.c
** File description:
** Function to make buttons clickable, on, out.
*/

#include "my.h"

void verrif_mouse_select(game_t *g)
{
    sfIntRect rect = pos_rect(0, 0, 48, 33);

    verrif_button(g, g->option.back.sprite, rect);
    verrif_button(g, g->option.quit.sprite, rect);
    verrif_button(g, g->power_up.buy.sprite, rect);
}

void verrif_mouse_achiev(game_t *g)
{
    sfIntRect rect = pos_rect(0, 0, 48, 33);

    verrif_button(g, g->option.back.sprite, rect);
    verrif_button(g, g->option.quit.sprite, rect);
}

void verrif_mouse_power(game_t *g)
{
    sfIntRect rect = pos_rect(0, 0, 48, 33);

    verrif_button(g, g->option.back.sprite, rect);
    verrif_button(g, g->option.quit.sprite, rect);
    verrif_button(g, g->power_up.buy.sprite, rect);
}

void verrif_mouse_option(game_t *g)
{
    sfIntRect rect = pos_rect(0, 0, 48, 33);

    verrif_button(g, g->option.back.sprite, rect);
    verrif_button(g, g->option.quit.sprite, rect);
    if (g->old_scene == 1) {
        verrif_button(g, g->start.resume, rect);
    }
}
