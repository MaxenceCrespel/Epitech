/*
** EPITECH PROJECT, 2022
** draw_select_char.c
** File description:
** Draw select character.
*/

#include "my.h"

void draw_buy_or_selct(game_t *g, sfSprite *cpy, sfText *two)
{
    if (g->save.perso[g->menu.select] == 0) {
        sfRenderWindow_drawSprite(g->window, g->power_up.coins.sprite,
        NULL);
        draw_price(g);
        sfSprite_setColor(cpy, sfBlack);
    } else
        sfText_setString(two, "Start");
}

void draw_over_select(game_t *g)
{
    sfSprite *cpy;
    sfText *t_cpy;
    sfColor color = sfSprite_getColor(g->menu.bg.sprite);
    sfText *two = sfText_copy(g->power_up.t_buy.text);
    sfSprite *buy = sfSprite_copy(g->power_up.buy.sprite);
    sfText_setPosition(two, set_pos(1076, 850));
    sfSprite_setColor(buy, color);
    if (g->menu.select != -1) {
        cpy = sfSprite_copy(g->select[g->menu.select].perso.sprite);
        t_cpy = sfText_copy(g->select[g->menu.select].name.text);
        sfSprite_setPosition(cpy, set_pos(680, 810));
        sfText_setPosition(t_cpy, set_pos(685, 780));
        sfRenderWindow_drawText(g->window, t_cpy, NULL);
        draw_buy_or_selct(g, cpy, two);
        sfRenderWindow_drawSprite(g->window, cpy, NULL);
        sfRenderWindow_drawText(g->window, t_cpy, NULL);
        sfRenderWindow_drawSprite(g->window, buy, NULL);
        sfRenderWindow_drawText(g->window, two, NULL);
    }
}

void draw_slt_perso(game_t *g, int i)
{
    sfSprite *cpy;
    if (g->save.perso[i] == 1) {
        sfRenderWindow_drawSprite(g->window, g->select[i].bg.sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->select[i].perso.sprite,
        NULL);
        sfRenderWindow_drawText(g->window, g->select[i].name.text, NULL);
    } else {
        cpy = sfSprite_copy(g->select[i].perso.sprite);
        sfSprite_setColor(cpy, sfBlack);
        sfRenderWindow_drawSprite(g->window, g->select[i].bg.sprite, NULL);
        sfRenderWindow_drawSprite(g->window, cpy, NULL);
        sfRenderWindow_drawText(g->window, g->select[i].name.text, NULL);
        sfSprite_destroy(cpy);
    }
}

void draw_select_perso(game_t *g)
{
    sfRenderWindow_drawSprite(g->window, g->menu.font.sprite, NULL);
    sfRenderWindow_drawText(g->window, g->menu.text.text, NULL);
    sfRenderWindow_drawSprite(g->window, g->option.back.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->option.quit.sprite, NULL);
    sfRenderWindow_drawText(g->window, g->option.t_back.text, NULL);
    sfRenderWindow_drawText(g->window, g->option.t_quit.text, NULL);
    sfRenderWindow_drawSprite(g->window, g->menu.over_bot.sprite, NULL);
    draw_over_select(g);
    for (int i = 0; g->select[i].bg.sprite; i++)
        draw_slt_perso(g, i);
    draw_stat_p(g);
}

void draw_achiev(game_t *g)
{
    sfRenderWindow_drawSprite(g->window, g->option.bg.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->option.back.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->option.quit.sprite, NULL);
    sfRenderWindow_drawText(g->window, g->option.t_quit.text, NULL);
    sfRenderWindow_drawText(g->window, g->option.t_back.text, NULL);
    for (int i = 0; g->achiev[i].img_opt.sprite != NULL; i++) {
        sfRenderWindow_drawSprite(g->window, g->achiev[i].img_opt.sprite,
        NULL);
        if (g->achiev[i].complete == 1)
            sfRenderWindow_drawSprite(g->window, g->achiev[i].oui.sprite,
            NULL);
        else
            sfRenderWindow_drawSprite(g->window, g->achiev[i].non.sprite,
            NULL);
        sfRenderWindow_drawText(g->window, g->achiev[i].text.text, NULL);
        sfRenderWindow_drawText(g->window, g->achiev[i].t_actu.text, NULL);
    }
}
