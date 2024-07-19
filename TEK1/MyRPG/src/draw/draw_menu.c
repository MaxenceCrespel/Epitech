/*
** EPITECH PROJECT, 2022
** draw_menu.c
** File description:
** Draw sprite menu.
*/

#include "my.h"

void my_event(game_t *g, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(g->window);
    if (g->scene == 1)
        event_game(g, event);
    if (event.type == sfEvtMouseButtonPressed && g->scene != 1)
        verrif_click(g);
    if (event.type == sfEvtMouseButtonPressed)
        sfSound_play(g->sound.sound[CLICK]);
    if (event.type == sfEvtKeyPressed && g->scene == -1) {
        g->scene = 0;
        sfSound_stop(g->sound.sound[INTRO]);
        sfMusic_play(g->music.music[0]);
    }
    if (event.type == sfEvtKeyPressed)
        event_key(g, event);
}

void draw_scene_zero(game_t *g)
{
    sfRenderWindow_drawSprite(g->window, g->menu.logo.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->menu.start.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->menu.option.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->menu.quit.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->menu.power.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->menu.achiev.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->menu.help.sprite, NULL);
    sfRenderWindow_drawText(g->window, g->menu.t_start.text, NULL);
    sfRenderWindow_drawText(g->window, g->menu.t_option.text, NULL);
    sfRenderWindow_drawText(g->window, g->menu.t_quit.text, NULL);
    sfRenderWindow_drawText(g->window, g->menu.t_power.text, NULL);
    sfRenderWindow_drawText(g->window, g->menu.t_achiev.text, NULL);
    sfRenderWindow_drawText(g->window, g->menu.t_help.text, NULL);
}

void draw_stat_p(game_t *g)
{
    sfRenderWindow_drawSprite(g->window, g->d_stat.bg.sprite, NULL);
    for (int i = 0; g->d_stat.stat_n[i].text; i++) {
        sfRenderWindow_drawText(g->window, g->d_stat.stat_n[i].text, NULL);
        sfRenderWindow_drawSprite(g->window, g->d_stat.stat_i[i].sprite, NULL);
        if (g->scene == 2 && g->menu.select != -1
        && g->save.perso[g->menu.select])
            sfRenderWindow_drawText(g->window, g->d_stat.t_stat[i].text, NULL);
    }
}

void draw_stat_in(game_t *g)
{
    sfSprite_setColor(g->d_stat.bg.sprite,
    sfColor_fromRGBA(255, 255, 255, 210));
    sfRenderWindow_drawSprite(g->window, g->d_stat.bg.sprite, NULL);
    for (int i = 0; g->d_stat.stat_n[i].text; i++) {
        sfRenderWindow_drawText(g->window, g->d_stat.stat_n[i].text, NULL);
        sfRenderWindow_drawSprite(g->window, g->d_stat.stat_i[i].sprite, NULL);
        sfRenderWindow_drawText(g->window, g->d_stat.t_stat[i].text, NULL);
    }
}

void draw_option_case(game_t *g, int i)
{
    sfRenderWindow_drawSprite(g->window, g->option.img[i].img_opt.sprite,
    NULL);
    sfRenderWindow_drawText(g->window, g->option.img[i].text.text, NULL);
    if (g->option.img[i].status == 1)
        sfRenderWindow_drawSprite(g->window, g->option.img[i].non.sprite,
        NULL);
    else
        sfRenderWindow_drawSprite(g->window, g->option.img[i].oui.sprite,
        NULL);
}
