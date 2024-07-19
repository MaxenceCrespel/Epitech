/*
** EPITECH PROJECT, 2022
** display_game
** File description:
** rpg
*/

#include "my.h"

int verrif_button_click(game_t *g, sfSprite *spr)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(spr);
    if (sfFloatRect_contains(&rect, g->mouse.x, g->mouse.y)) {
        return (1);
    }
    return 0;
}

void click_menu(game_t *g)
{
    click_flag(g);
    if (verrif_button_click(g, g->menu.start.sprite))
        press_buttons(g, g->menu.start.sprite, 67, 2);
    if (verrif_button_click(g, g->menu.option.sprite)) {
        g->old_scene = 0;
        press_buttons(g, g->menu.option.sprite, 67, 5);
    }
    if (verrif_button_click(g, g->menu.quit.sprite)) {
        press_buttons(g, g->menu.quit.sprite, 67, -1);
        sfRenderWindow_close(g->window);
    }
    if (verrif_button_click(g, g->menu.power.sprite))
        press_buttons(g, g->menu.power.sprite, 67, 6);
    if (verrif_button_click(g, g->menu.achiev.sprite))
        press_buttons(g, g->menu.achiev.sprite, 67, 7);
    if (verrif_button_click(g, g->menu.help.sprite))
        press_buttons(g, g->menu.help.sprite, 67, 10);
}

int set_volume(game_t *g)
{
    if (g->option.img[0].status == 1) {
        g->sound.status = 1;
    }
    if (g->option.img[0].status == 0) {
        g->sound.status = 0;
    }
    if (g->option.img[1].status == 1) {
        g->music.status = 1;
    }
    if (g->option.img[1].status == 0) {
        g->music.status = 0;
    }
    return (0);
}

void click_option_two(game_t *g)
{
    for (int i = 0; i < 4; i++) {
        if (verrif_button_click(g, g->option.img[i].img_opt.sprite)
        && g->option.img[i].status == 0) {
            g->option.img[i].status = 1;
            continue;
        }
        if (verrif_button_click(g, g->option.img[i].img_opt.sprite)
        && g->option.img[i].status == 1)
            g->option.img[i].status = 0;
    }
    if (verrif_button_click(g, g->option.quit.sprite))
        sfRenderWindow_close(g->window);
    if (g->old_scene == 1 && verrif_button_click(g, g->option.back.sprite)) {
        press_buttons(g, g->option.back.sprite, 67, -1);
        quit_game(g);
    }
}

void click_option(game_t *g)
{
    int tmp;
    click_option_two(g);
    if (verrif_button_click(g, g->option.back.sprite) && g->old_scene != 1) {
        press_buttons(g, g->option.back.sprite, 67, -1);
        tmp = g->scene;
        g->scene = g->old_scene;
        g->old_scene = tmp;
    } else if (g->old_scene == 1 &&
    verrif_button_click(g, g->start.resume)) {
        sound_pause(g);
        press_buttons(g, g->start.resume, 67, 1);
    }
}
