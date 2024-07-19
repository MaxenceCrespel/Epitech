/*
** EPITECH PROJECT, 2022
** ft_buttons2.c
** File description:
** Function to make buttons clickable, on, out.
*/

#include "my.h"

void click_lose(game_t *g)
{
    if (verrif_button_click(g, g->lose.quit.sprite)) {
        press_buttons(g, g->lose.quit.sprite, 67, -1);
        sfRenderWindow_close(g->window);
    }
    if (verrif_button_click(g, g->lose.menu.sprite)) {
        press_buttons(g, g->lose.menu.sprite, 67, -1);
        quit_game(g);
    }
}

void verrif_mouse_lose(game_t *g)
{
    sfIntRect rect = pos_rect(0, 0, 48, 33);

    verrif_button(g, g->lose.menu.sprite, rect);
    verrif_button(g, g->lose.quit.sprite, rect);
}
