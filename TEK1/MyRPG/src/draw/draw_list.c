/*
** EPITECH PROJECT, 2022
** draw_list
** File description:
** rpg
*/

#include "my.h"

void click_select_two(game_t *g, int nb)
{
    if (g->menu.select != -1 && verrif_button_click(g, g->power_up.buy.sprite)
    && g->save.perso[g->menu.select] == 1)
        return (init_start(g, nb));
    if (verrif_button_click(g, g->option.quit.sprite)) {
        press_buttons(g, g->option.quit.sprite, 67, -1);
        sfRenderWindow_close(g->window);
    }
    if (verrif_button_click(g, g->option.back.sprite))
        press_buttons(g, g->option.back.sprite, 67, 0);
    if (verrif_button_click(g, g->power_up.buy.sprite)
    && g->save.perso[g->menu.select] == 0) {
        press_buttons(g, g->power_up.buy.sprite, 67, -1);
        buy_perso(g);
    }
}

void click_select(game_t *g)
{
    static int nb = -1;
    int start = -1;
    int touch = 0;
    for (int i = 0; g->select[i].bg.sprite; i++) {
        if (verrif_button_click(g, g->select[i].bg.sprite)) {
            sfSprite_setColor(g->select[i].bg.sprite, sfYellow);
            nb == i ? start = 1 : 0;
            nb = i;
            g->menu.select = i;
            touch++;
        } else
            sfSprite_setColor(g->select[i].bg.sprite, sfWhite);
    }
    if (start == 1 && g->save.perso[g->menu.select])
        return (init_start(g, nb));
    click_select_two(g, nb);
    if (touch == 0 && !verrif_button_click(g, g->menu.over_bot.sprite)) {
        g->menu.select = -1;
        nb = -1;
    }
}

void change_stat(game_t *g, int attack)
{
    if (attack == 4)
        g->start.perso.ms += 2;
    if (attack == 5)
        g->start.perso.cooldown += 5;
    if (attack == 3)
        g->start.lorel_max += 1;
}

void level_up_attack(game_t *g, int attack)
{
    for (int i = 0; i < 6; i++)
        if (g->start.attack[i].status == attack) {
            g->start.attack[i].lvl++;
            change_stat(g, attack);
        }
}

void add_attack(game_t *g, int attack)
{
    int i = 0;
    if (attack > 2)
        i = 3;
    else
        i = 0;
    for (; g->start.attack[i].status != -1; i++);
    g->start.attack[i].att = g->stat_attack[attack];
    g->start.attack[i].lvl++;
    change_stat(g, attack);
    g->start.attack[i].clock = sfClock_create();
    g->start.attack[i].status = attack;
    g->start.attack[i].have = 1;
    sfSprite_setPosition(g->start.attack[i].att.img.sprite,
    set_pos(735 + (i * 80), 830));
}
