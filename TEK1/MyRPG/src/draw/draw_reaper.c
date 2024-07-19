/*
** EPITECH PROJECT, 2022
** draw reaper
** File description:
** rpg
*/

#include "my.h"

void draw_reaper(game_t *g)
{
    sfRenderWindow_drawSprite(g->window, g->reaper.reaper.sprite, NULL);
}
