/*
** EPITECH PROJECT, 2022
** ft_power_select.c
** File description:
** Function to select power up.
*/

#include "my.h"

void click_lvl_up(game_t *g)
{
    if (verrif_button_click(g, g->level_up.chose1.bg.sprite)) {
        if (g->level_up.chose1.have == 1)
            level_up_attack(g, g->level_up.nb1);
        else
            add_attack(g, g->level_up.nb1);
        g->scene = 1;
    }
    if (verrif_button_click(g, g->level_up.chose2.bg.sprite)) {
        if (g->level_up.chose2.have == 1)
            level_up_attack(g, g->level_up.nb2);
        else
            add_attack(g, g->level_up.nb2);
        g->scene = 1;
    }
}

void copy_power_select_price(game_t *g, int nb)
{
    sfColor test = sfSprite_getColor(g->power_up.list[nb].icon.sprite);
    if (g->power_up.list[nb].have_nb == 0)
        sfText_setString(g->power_up.price.text, "100");
    if (g->power_up.list[nb].have_nb == 1)
        sfText_setString(g->power_up.price.text, "200");
    if (g->power_up.list[nb].have_nb == 2)
        sfText_setString(g->power_up.price.text, "300");
    if (g->power_up.list[nb].have_nb == 3)
        sfText_setString(g->power_up.price.text, "");
    if (g->power_up.list[nb].have_nb == 3) {
        sfSprite_setColor(g->power_up.buy.sprite, sfRed);
        sfSprite_setColor(g->power_up.coins.sprite,
        sfColor_fromRGBA(0, 0, 0, 0));
    } else {
        sfSprite_setColor(g->power_up.buy.sprite, test);
        sfSprite_setColor(g->power_up.coins.sprite, test);
    }
}

void copy_power_select(game_t *g, int nb)
{
    g->power_up.select.fond.sprite =
    sfSprite_copy(g->power_up.list[nb].fond.sprite);
    sfSprite_setPosition(g->power_up.select.fond.sprite, set_pos(700, 810));
    g->power_up.select.icon.sprite =
    sfSprite_copy(g->power_up.list[nb].icon.sprite);
    sfSprite_setPosition(g->power_up.select.icon.sprite, set_pos(710, 823));
    g->power_up.select.name.text = sfText_copy(g->power_up.list[nb].name.text);
    sfText_setPosition(g->power_up.select.name.text, set_pos(680, 780));
    sfText_setString(g->power_up.description.text,
    langage[g->option.langage][3][nb]);
    copy_power_select_price(g, nb);
}

void augment_power(game_t *g, int nb)
{
    if (g->save.i_or >= (g->power_up.list[nb].have_nb + 1) * 100) {
        g->save.i_or -= (g->power_up.list[nb].have_nb + 1) * 100;
        g->power_up.list[nb].have_nb++;
        nb == 0 ? g->save.max_life++ : 0;
        nb == 1 ? g->save.recov++ : 0;
        nb == 2 ? g->save.ms++ : 0;
        nb == 3 ? g->save.armor++ : 0;
        nb == 4 ? g->save.area++ : 0;
        nb == 5 ? g->save.speed++ : 0;
        nb == 6 ? g->save.cooldown++ : 0;
        nb == 7 ? g->save.pene++ : 0;
        nb == 8 ? g->save.duration++ : 0;
        nb == 9 ? g->save.magnet++ : 0;
        nb == 10 ? g->save.growth++ : 0;
        if (g->power_up.list[nb].have_nb == 3)
            sfSprite_setColor(g->power_up.list[nb].bg.sprite,
            sfColor_fromRGBA(255, 255, 140, 255));
        copy_power_select_price(g, nb);
        sfText_setString(g->save.t_or.text, my_itoa(g->save.i_or));
    }
}
