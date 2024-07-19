/*
** EPITECH PROJECT, 2022
** condition 8
** File description:
** add fucntion
*/

#include "my.h"

void remove_text(game_t *g, add_text_t **actuel)
{
    add_text_t *prev = NULL;
    add_text_t *attack = *actuel;
    sfTime time;

    while (attack) {
        time = sfClock_getElapsedTime(attack->time);
        if (sfTime_asMilliseconds(time) >= 400) {
            delete_text(&attack, prev, actuel);
            g->start.nb_text--;
        } else {
            prev = attack;
            attack = attack->next;
        }
    }
}

void regen_life(game_t *g)
{
    sfTime time = sfClock_getElapsedTime(g->start.regen);
    if (g->start.perso.life == g->start.perso.max_life)
        return;
    if (sfTime_asMilliseconds(time) >= 1000) {
        if ((g->start.perso.life += g->start.perso.recov)
        > g->start.perso.max_life)
            g->start.perso.life = g->start.perso.max_life;
        else
            g->start.perso.life += g->start.perso.recov;
        change_bar_hp(g->start.bar, g->start.perso.life,
        g->start.perso.max_life);
        sfClock_restart(g->start.regen);
    }
}

add_monster_t *add_monster(game_t *g, int nb, add_monster_t *llist)
{
    add_monster_t *element = malloc(sizeof(add_monster_t));
    element->sprite.sprite = sfSprite_copy(g->stat_m[nb].sprite.sprite);
    element->time = sfClock_create();
    element->atta = sfClock_create();
    sfSprite_setPosition(element->sprite.sprite, get_pos_monster());
    element->dir = set_pos(0, 0);
    element->life = g->stat_m[nb].life;
    element->speed = g->stat_m[nb].speed;
    element->rect = g->stat_m[nb].rect;
    element->nb_rect = 0;
    element->next = llist;
    element->type = nb;
    element->damage = g->stat_m[nb].damage;
    g->start.nb_monster++;
    return element;
}

void spawn_monster(game_t *g)
{
    sfTime time = sfClock_getElapsedTime(g->start.monster);
    int add = 0;
    if (g->start.nb_item >= 3)
        add = 3;
    int alea = (rand() % 3) + add;
    if (sfTime_asMilliseconds(time) >= 1500) {
        g->start.d_monster = add_monster(g, alea, g->start.d_monster);
        sfClock_restart(g->start.monster);
    }
}

int mirror_monster(game_t *g)
{
    sfVector2f pos;
    add_monster_t *tmp = g->start.d_monster;

    while (tmp) {
        pos = sfSprite_getPosition(tmp->sprite.sprite);
        if (pos.x > 960)
            sfSprite_setScale(tmp->sprite.sprite, set_pos(3, 3));
        if (pos.x <= 960)
            sfSprite_setScale(tmp->sprite.sprite, set_pos(-3, 3));
        tmp = tmp->next;
    }
}
