/*
** EPITECH PROJECT, 2022
** monster attack
** File description:
** rpg
*/

#include "my.h"

int monster_move(game_t *g, add_monster_t *tmp)
{
    if (monst_can_move(g, tmp))
        sfSprite_move(tmp->sprite.sprite,
        calc_path_monster(g, tmp->sprite.sprite, tmp->speed));
    else
        monster_attack(g, tmp);
}

void monster_attack(game_t *g, add_monster_t *tmp)
{
    sfTime time;
    time = sfClock_getElapsedTime(tmp->atta);
    if (sfTime_asMilliseconds(time) >= 1500) {
        sfClock_restart(tmp->atta);
        take_damage(g, tmp->damage);
    }
    tmp = tmp->next;
}
