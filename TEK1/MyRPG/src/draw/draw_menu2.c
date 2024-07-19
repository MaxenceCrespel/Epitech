/*
** EPITECH PROJECT, 2022
** draw_menu2.c
** File description:
** Draw sprite menu.
*/

#include "my.h"

void draw_helper(game_t *g)
{
    sfRenderWindow_drawSprite(g->window, g->help.help.sprite, NULL);
}

void display_flag(game_t *g)
{
    if (g->scene == 0) {
        draw_scene_zero(g);
        draw_flag(g);
    }
}

void draw_menu(game_t *g)
{
    sfRenderWindow_drawSprite(g->window, g->menu.bg.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->menu.vamp.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->menu.pers2.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->menu.pers.sprite, NULL);
    sfRenderWindow_drawRectangleShape(g->window, g->menu.but2, NULL);
    sfRenderWindow_drawSprite(g->window, g->menu.coin.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->menu.img_coin.sprite, NULL);
    sfRenderWindow_drawText(g->window, g->save.t_or.text, NULL);
    display_flag(g);
    if (g->scene == 6)
        draw_power_up(g);
    if (g->scene == 2)
        draw_select_perso(g);
    if (g->scene == 5)
        draw_option(g);
    if (g->scene == 7)
        draw_achiev(g);
    if (g->scene == 10)
        draw_helper(g);
}

void draw_sprite(add_sprite *list, game_t *g)
{
    while (list) {
        sfRenderWindow_drawSprite(g->window, list->sprite, NULL);
        list = list->next;
    }
}
