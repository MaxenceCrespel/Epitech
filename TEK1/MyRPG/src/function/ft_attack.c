/*
** EPITECH PROJECT, 2022
** ft_attack.c
** File description:
** Function to attack.
*/

#include "my.h"

void move_map(game_t *g, sfVector2f move)
{
    sfTime time = sfClock_getElapsedTime(g->start.clock_map);
    if (sfTime_asMilliseconds(time) >= 30 && !touch_tree(g, move)) {
        move_map2(g->start.map, move);
        change_pos_game(g, move);
        if (g->start.nb_attack > 0)
            move_attack_map(g->start.d_attack, move);
        if (g->start.nb_monster > 0)
            move_monster_map(g->start.d_monster, move);
        if (g->start.nb_text > 0)
            move_text_map(g->start.d_text, move);
        if (g->start.nb_cryst > 0)
            move_cryst_map(g->start.d_crys, move);
        sfSprite_move(g->reaper.reaper.sprite, move);
        move_tree(g, move);
        move_item_map(g, move);
        sfClock_restart(g->start.clock_map);
    }
}

void add_gold(game_t *g, int nb)
{
    g->save.i_or += nb;
    int len = ((my_strlen(my_itoa(g->save.i_or)) - 1) * 25);
    g->save.t_or = init_text("assets/fonts/KO.ttf", 40,
    set_pos(1050 - len, 22), my_itoa(g->save.i_or));
}

void fouet_dir(game_t *g, add_attack_t *element, int nb)
{
    if (nb == 1) {
        sfSprite_rotate(element->sprite.sprite, 180);
        sfSprite_move(element->sprite.sprite, set_pos(-100, 20));
    }
}

add_attack_t *new_attack(game_t *g, int nb, add_attack_t *llist)
{
    add_attack_t *element = malloc(sizeof(add_attack_t));
    element->sprite.sprite = sfSprite_copy(g->stat_attack[nb].vfx.sprite);
    sfVector2f sc = sfSprite_getScale(element->sprite.sprite);
    float x = (100 + (float)g->start.perso.area) / 100;
    float y = (100 + (float)g->start.perso.area) / 100;
    sfSprite_scale(element->sprite.sprite, set_pos(x, y));
    element->time = sfClock_create();
    element->max_time = g->stat_attack[nb].max_time;
    element->status = nb;
    element->hit = 1;
    element->damage = g->stat_attack[nb].dama + g->save.pene;
    if (nb == 0)
        fouet_dir(g, element, g->start.r_l);
    if (nb == 1)
        element->dir = calc_dir(g->mouse, element->sprite.sprite);
    else if (nb == 2)
        dir_dague(g, element, g->start.dir);
    element->next = llist;
    g->start.nb_attack++;
    return element;
}

void attack_zero(game_t *g)
{
    if (g->start.attack[0].have == 1) {
        g->start.d_attack = new_attack(g, g->start.attack[0].status,
        g->start.d_attack);
        g->start.d_attack->damage += 10 + (g->start.attack[0].lvl - 1) * 3;
        if (g->start.attack[0].lvl >= 3 && g->start.attack[0].status == 2) {
            g->start.d_attack = new_knife(g, g->start.attack[0].status,
            g->start.d_attack);
            g->start.d_attack->damage += 10 + (g->start.attack[0].lvl - 1) * 3;
        }
        if (g->start.attack[0].lvl >= 3 && g->start.attack[0].status == 0) {
            g->start.d_attack = new_fouet(g, g->start.attack[0].status,
            g->start.d_attack);
            g->start.d_attack->damage += 10 + (g->start.attack[0].lvl - 1) * 3;
        }
        sfClock_restart(g->start.attack[0].clock);
        sound_attack(g, g->start.attack[0].status);
    }
}
