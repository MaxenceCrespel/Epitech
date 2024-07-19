/*
** EPITECH PROJECT, 2022
** condition2.c
** File description:
** rpg
*/

#include "my.h"

void delete_monster(add_monster_t **attack, add_monster_t *prev,
add_monster_t **list)
{
    add_monster_t *temp = NULL;
    if (prev == NULL) {
        temp = (*attack)->next;
        sfSprite_destroy((*attack)->sprite.sprite);
        *attack = temp;
        *list = temp;
    } else {
        prev->next = (*attack)->next;
        sfSprite_destroy((*attack)->sprite.sprite);
        *attack = prev->next;
    }
}

add_text_t *new_text_damage(game_t *g, add_text_t *llist,
add_attack_t *tmp, add_monster_t *mons)
{
    add_text_t *element = malloc(sizeof(add_text_t));
    element->pos = sfSprite_getPosition(mons->sprite.sprite);
    element->time = sfClock_create();
    element->damage = init_text("assets/fonts/KO.ttf", 30, element->pos,
    my_itoa(tmp->damage));
    element->next = llist;
    g->start.nb_text++;
    return element;
}

void monster_take_damage(game_t *g, add_monster_t *tmp, add_attack_t *att)
{
    tmp->life = tmp->life - att->damage;
    g->start.d_text = new_text_damage(g, g->start.d_text, att, tmp);
    sfSound_play(g->sound.sound[HIT]);
}

int verrif_hit(add_attack_t *tmp, game_t *g)
{
    int ret = 0;
    add_monster_t *monster = g->start.d_monster;
    sfVector2f pos;
    sfFloatRect rect_m;
    sfFloatRect rect = sfSprite_getGlobalBounds(tmp->sprite.sprite);
    while (monster) {
        rect_m = sfSprite_getGlobalBounds(monster->sprite.sprite);
        if (sfFloatRect_intersects(&rect, &rect_m, NULL)) {
            monster_take_damage(g, monster, tmp);
            ret = 1;
        }
        monster = monster->next;
    }
    return ret;
}

void verrif_delete_attack(game_t *g, add_attack_t **actuel)
{
    add_attack_t *prev_attak = NULL;
    add_attack_t *attack = *actuel;
    sfTime time;
    while (attack) {
        if (attack->hit == 1 && verrif_hit(attack, g) == 1)
            attack->hit = 0;
        if (attack->status != 0 && attack->hit == 0) {
            delete_attack(&attack, prev_attak, actuel, g);
            continue;
        }
        time = sfClock_getElapsedTime(attack->time);
        if (sfTime_asMilliseconds(time) >= attack->max_time +
        ((attack->max_time / 100) * g->start.perso.duration)) {
            delete_attack(&attack, prev_attak, actuel, g);
        } else {
            prev_attak = attack;
            attack = attack->next;
        }
    }
}
