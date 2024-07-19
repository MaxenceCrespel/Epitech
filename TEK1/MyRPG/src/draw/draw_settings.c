/*
** EPITECH PROJECT, 2022
** draw_settings.c
** File description:
** Draw settings.
*/

#include "my.h"

void draw_option(game_t *g)
{
    draw_option_mod(g);
    sfRenderWindow_drawSprite(g->window, g->option.bg.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->option.back.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->option.quit.sprite, NULL);
    sfRenderWindow_drawText(g->window, g->option.t_quit.text, NULL);
    sfText *cpy = sfText_copy(g->option.t_back.text);
    if (g->old_scene == 1) {
        sfRenderWindow_drawSprite(g->window, g->start.resume, NULL);
        sfRenderWindow_drawText(g->window, g->start.t_resume, NULL);
        sfText_setString(cpy, "MENU");
    }
    sfRenderWindow_drawText(g->window, cpy, NULL);
    for (int i = 0; i < 4; i++)
        draw_option_case(g, i);
}

void draw_descri_power(game_t *g)
{
    sfRenderWindow_drawSprite(g->window, g->menu.over_bot.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->power_up.select.fond.sprite, NULL);
    sfRenderWindow_drawText(g->window, g->power_up.select.name.text, NULL);
    sfRenderWindow_drawText(g->window, g->power_up.description.text, NULL);
    sfRenderWindow_drawSprite(g->window, g->power_up.select.icon.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->power_up.buy.sprite, NULL);
    sfRenderWindow_drawText(g->window, g->power_up.t_buy.text, NULL);
    sfRenderWindow_drawSprite(g->window, g->power_up.coins.sprite, NULL);
    sfRenderWindow_drawText(g->window, g->power_up.price.text, NULL);
}

void draw_img_descri(game_t *g, int i)
{
    sfRenderWindow_drawSprite(g->window, g->power_up.list[i].bg.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->power_up.list[i].fond.sprite,
    NULL);
    sfRenderWindow_drawSprite(g->window, g->power_up.list[i].icon.sprite,
    NULL);
    sfRenderWindow_drawText(g->window, g->power_up.list[i].name.text, NULL);
    for (int e = 0; g->power_up.list[i].square[e].sprite; e++)
        sfRenderWindow_drawSprite(g->window,
        g->power_up.list[i].square[e].sprite, NULL);
    for (int e = 0; e < g->power_up.list[i].have_nb; e++)
        sfRenderWindow_drawSprite(g->window,
        g->power_up.list[i].oui[e].sprite, NULL);
}

void draw_power_up(game_t *g)
{
    sfRenderWindow_drawSprite(g->window, g->option.bg.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->option.back.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->option.quit.sprite, NULL);
    sfRenderWindow_drawText(g->window, g->option.t_back.text, NULL);
    sfRenderWindow_drawText(g->window, g->option.t_quit.text, NULL);
    for (int i = 0; g->power_up.list[i].bg.sprite; i++)
        draw_img_descri(g, i);
    if (g->power_up.display != -1)
        draw_descri_power(g);
}

void draw_price(game_t *g)
{
    sfText *cpy = sfText_copy(g->power_up.price.text);
    sfText_setString(cpy, "300");
    sfRenderWindow_drawText(g->window, cpy, NULL);
}
