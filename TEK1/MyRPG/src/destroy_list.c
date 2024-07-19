/*
** EPITECH PROJECT, 2022
** destroy
** File description:
** rpg
*/

#include "my.h"

void destroy_list(add_monster_t **actual)
{
    add_monster_t *prev = *actual;
    while (*actual) {
        sfSprite_destroy((*actual)->sprite.sprite);
        sfClock_destroy((*actual)->atta);
        sfClock_destroy((*actual)->time);
        prev = *actual;
        *actual = (*actual)->next;
        free(prev);
    }
}
