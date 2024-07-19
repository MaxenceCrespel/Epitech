/*
** EPITECH PROJECT, 2022
** add two knife
** File description:
** add knife
*/

#include "my.h"

add_attack_t *new_knife(game_t *g, int nb, add_attack_t *llist)
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
    if (nb == 2)
        dir_dague(g, element, g->start.dir + 1);
    element->next = llist;
    g->start.nb_attack++;
    return element;
}

void fouet_dir_bis(game_t *g, add_attack_t *element, int nb)
{
    if (nb == 0) {
        sfSprite_rotate(element->sprite.sprite, 180);
        sfSprite_move(element->sprite.sprite, set_pos(-100, 20));
    }
}

add_attack_t *new_fouet(game_t *g, int nb, add_attack_t *llist)
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
        fouet_dir_bis(g, element, g->start.r_l);
    element->next = llist;
    g->start.nb_attack++;
    return element;
}
