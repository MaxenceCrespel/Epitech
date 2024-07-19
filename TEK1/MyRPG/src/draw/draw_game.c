/*
** EPITECH PROJECT, 2022
** draw_game.c
** File description:
** Draw sprite game.
*/

#include "my.h"

void draw_item(game_t *g)
{
    for (int i = 0; i < 6; i++) {
        if (g->start.item[i].have == 1)
            sfRenderWindow_drawSprite(g->window,
            g->start.item[i].img.sprite, NULL);
    }
}

void draw_sprite_item(game_t *g)
{
    for (int i = 0; i < 6; i++)
        if (g->item_l[i].status == 1)
            sfRenderWindow_drawSprite(g->window,
            g->item_l[i].img.sprite, NULL);
}

void draw_info_text(game_t *g)
{
    sfSprite *cpy = sfSprite_copy(g->power_up.coins.sprite);
    sfSprite_setPosition(cpy, set_pos(1628, 80));
    sfText_setCharacterSize(g->start.t_lev.text, 40);
    sfText_setStyle(g->start.t_lev.text, sfTextBold);
    sfText_setPosition(g->start.t_lev.text, set_pos(1785, 0));
    sfRenderWindow_drawSprite(g->window, cpy, NULL);
    sfRenderWindow_drawSprite(g->window, g->img_k_m.sprite, NULL);
    sfRenderWindow_drawText(g->window, g->start.t_lev.text, NULL);
    sfRenderWindow_drawText(g->window, g->start.t_or.text, NULL);
    sfRenderWindow_drawText(g->window, g->start.t_pos_x.text, NULL);
    sfRenderWindow_drawText(g->window, g->start.t_pos_y.text, NULL);
    sfRenderWindow_drawText(g->window, g->start.t_mons_kill.text, NULL);
    sfSprite_destroy(cpy);
}

void draw_game_other_scene(game_t *g)
{
    if (g->scene == 5)
        draw_option(g);
    if (g->scene == 4) {
        display_overlay(g);
        sfRenderWindow_drawSprite(g->window, g->level_up.bg.sprite, NULL);
        sfRenderWindow_drawText(g->window, g->level_up.level_up.text, NULL);
        sfRenderWindow_drawText(g->window, g->level_up.info.text, NULL);
        draw_chose(g);
    }
}

void display_game(game_t *g)
{
    sfRenderWindow_clear(g->window, sfBlue);
    draw_sprite(g->start.map, g);
    draw_reaper(g);
    if (g->start.lorel >= 1)
        display_lorel(g, g->stat_attack[3].vfx.sprite, g->start.lorel);
    draw_sprite_item(g);
    display_arbre(g);
    sfRenderWindow_drawSprite(g->window, g->start.perso.sprite.sprite, NULL);
    display_bar_life(g, g->start.bar);
    display_game_two(g);
    sfRenderWindow_drawRectangleShape(g->window, g->start.empty_bar, NULL);
    sfRenderWindow_drawRectangleShape(g->window, g->start.bar_xp, NULL);
    draw_info_text(g);
    sfRenderWindow_drawSprite(g->window, g->arrow.sprite, NULL);
    draw_game_other_scene(g);
}
