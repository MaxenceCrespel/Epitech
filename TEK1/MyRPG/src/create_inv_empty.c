/*
** EPITECH PROJECT, 2022
** creat empty
** File description:
** rpg
*/

#include "my.h"

item_t *create_inv_empty(game_t *g)
{
    item_t *list = malloc(sizeof(item_t) * 6);
    sfTexture *bg = sfTexture_createFromFile("assets/img/items.png", NULL);
    for (int i = 0; i < 6; i++) {
        list[i].have = 0;
        list[i].img.sprite = NULL;
    }
    return list;
}
