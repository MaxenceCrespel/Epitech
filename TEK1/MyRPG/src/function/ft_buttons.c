/*
** EPITECH PROJECT, 2022
** ft_buttons.c
** File description:
** Function to make buttons clickable, on, out.
*/

#include "my.h"

void verrif_button(game_t *g, sfSprite *sprite, sfIntRect rect)
{
    sfIntRect rect2 = rect;

    rect2.top = 34;
    if (verrif_button_click(g, sprite) == 1) {
        sfSprite_setTextureRect(sprite, rect2);
    } else {
        sfSprite_setTextureRect(sprite, rect);
    }
}

void animate_buttons(game_t *g)
{
    if (g->scene == 0)
        verrif_mouse_menu(g);
    if (g->scene == 2)
        verrif_mouse_select(g);
    if (g->scene == 5)
        verrif_mouse_option(g);
    if (g->scene == 6)
        verrif_mouse_power(g);
    if (g->scene == 7)
        verrif_mouse_achiev(g);
    if (g->scene == 9)
        verrif_mouse_lose(g);
}

int press_buttons(game_t *g, sfSprite *sprite, int top, int scene)
{
    sfIntRect rect = pos_rect(0, 0, 48, 33);

    rect.top = top;
    sfSprite_setTextureRect(sprite, rect);
    sfRenderWindow_drawSprite(g->window, sprite, NULL);
    sfRenderWindow_display(g->window);
    if (scene != -1)
        g->scene = scene;
    return (0);
}

void verrif_mouse_menu(game_t *g)
{
    sfIntRect rect = pos_rect(0, 0, 48, 33);

    verrif_button(g, g->menu.option.sprite, rect);
    verrif_button(g, g->menu.achiev.sprite, rect);
    verrif_button(g, g->menu.power.sprite, rect);
    verrif_button(g, g->menu.start.sprite, rect);
    verrif_button(g, g->menu.help.sprite, rect);
    verrif_button(g, g->menu.quit.sprite, rect);
    in_flag(g);
}
