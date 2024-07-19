/*
** EPITECH PROJECT, 2022
** ft_verrif_click.c
** File description:
** Function to verrif click.
*/

#include "my.h"

void click_achiev(game_t *g)
{
    if (verrif_button_click(g, g->option.quit.sprite)) {
        press_buttons(g, g->option.quit.sprite, 67, -1);
        sfRenderWindow_close(g->window);
    }
    if (verrif_button_click(g, g->option.back.sprite))
        press_buttons(g, g->option.quit.sprite, 67, 0);
}

void verrif_click(game_t *g)
{
    switch (g->scene) {
        case (0) : click_menu(g);
            break;
        case (2) : click_select(g);
            break;
        case (4) : click_lvl_up(g);
            break;
        case (5) : click_option(g);
            break;
        case (6) : click_power(g);
            break;
        case (7) : click_achiev(g);
            break;
        case (9) : click_lose(g);
            break;
        case (10) : click_help(g);
            break;
    }
}

void move(game_t *g)
{
    static int n = 1;
    sfTime time = sfClock_getElapsedTime(g->start.clock);
    float meter;
    if (sfTime_asMilliseconds(time) >= 150) {
        int i = g->start.perso.dir;
        if (i + n > 3 || i + n < 1)
            n = n * (-1);
        i = i + n;
        sfSprite_setTextureRect(g->start.perso.sprite.sprite,
        g->start.perso.rect[i]);
        g->start.perso.dir = i;
        sfClock_restart(g->start.clock);
        meter = g->start.perso.ms / 6;
        g->achiev[2].actu += meter;
    }
}

void move_map2(add_sprite *plat, sfVector2f move)
{
    add_sprite *tmp = plat;

    while (tmp) {
        sfSprite_move(tmp->sprite, move);
        tmp = tmp->next;
    }
}

void move_attack_map(add_attack_t *att, sfVector2f move)
{
    add_attack_t *tmp = att;

    while (tmp) {
        if (tmp->status != 0)
            sfSprite_move(tmp->sprite.sprite, move);
        tmp = tmp->next;
    }
}
