/*
** EPITECH PROJECT, 2022
** overlay_gem.c
** File description:
** Function to display gem overlay.
*/

#include "my.h"

int loop_set_color(game_t *g)
{
    switch (g->lay.color) {
        case (0):
            sfRectangleShape_setFillColor(g->lay.empty_bar, sfYellow);
            g->lay.color += 1;
            break;
        case (1):
            sfRectangleShape_setFillColor(g->lay.empty_bar, sfRed);
            g->lay.color += 1;
            break;
        case (2):
            sfRectangleShape_setFillColor(g->lay.empty_bar, sfMagenta);
            g->lay.color += 1;
            break;
        default:
            loop_set_color_end(g);
            break;
    }
}

int animate_gem(game_t *g)
{
    int i = 0;
    sfTime time = sfClock_getElapsedTime(g->lay.clock);
    sfTime time2 = sfClock_getElapsedTime(g->lay.clock2);
    float minus = 0.02;

    if (sfTime_asMilliseconds(time) >= 20) {
        animate_gem_end(g, i, minus, time);
    }
    if (sfTime_asMilliseconds(time2) >= 200) {
        loop_set_color(g);
        sfClock_restart(g->lay.clock2);
    }
    return (0);
}

int loop_initer_gem(game_t *g)
{
    int i = 400;
    int n = 0;
    int max = 500;
    int min = 375;
    float scale = 2.25;

    while (i >= 0) {
        if (i == 300 || i == 200 || i == 100) {
            max -= 125;
            min -= 125;
            scale += 0.25;
        }
        if (g->lay.y[i] >= 1020) {
            n = rand() % max + min;
            g->lay.y[i] = n;
            g->lay.scale[i] = scale;
        }
        i--;
    }
    return (0);
}

int display_overlay(game_t *g)
{
    int i = 400;

    animate_gem(g);
    loop_initer_gem(g);
    while (i >= 0) {
        sfRenderWindow_drawSprite(g->window, g->lay.gem[i].sprite, NULL);
        i--;
    }
    sfRenderWindow_drawRectangleShape(g->window, g->lay.empty_bar, NULL);
    return (0);
}
