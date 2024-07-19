/*
** EPITECH PROJECT, 2022
** overlay
** File description:
** always
*/

#include "my.h"

int init_bar_loop(game_t *g)
{
    g->lay.empty_bar = sfRectangleShape_create();
    sfRectangleShape_setSize(g->lay.empty_bar, set_pos(1916, 46));
    sfRectangleShape_setPosition(g->lay.empty_bar, set_pos(2, 2));
    sfRectangleShape_setFillColor(g->lay.empty_bar, sfBlack);
    sfRectangleShape_setOutlineThickness(g->lay.empty_bar, 2);
    sfRectangleShape_setOutlineColor(g->lay.empty_bar, sfYellow);
}

int init_sprite_gem(game_t *g)
{
    sfTexture **texture = init_texture_gem(g);
    g->lay.gem = malloc(sizeof(my_sprite_t) * 401);
    g->lay.x = random_x(g, 1800, 40, 400);
    g->lay.y = random_y(g, 125, 0, 400);
    g->lay.scale = my_tab_of_float(3, 400);
    int nb = 0;
    int rota = 0;
    for (int i = 0; i <= 400; i++) {
        if (i == 100 || i == 200 || i == 300)
            g->lay.scale[i] -= 0.25;
        nb = rand() % 9 + 1;
        rota = rand() % 360 + 0;
        g->lay.gem[i] = set_sprite(texture[nb],
        set_pos(g->lay.x[i], g->lay.y[i]),
        set_pos(g->lay.scale[i], g->lay.scale[i]));
        sfSprite_setRotation(g->lay.gem[i].sprite, rota);
    }
    return (0);
}

int init_overlay_gem(game_t *g)
{
    init_sprite_gem(g);
    init_bar_loop(g);
    g->lay.clock = sfClock_create();
    g->lay.clock2 = sfClock_create();
    g->lay.color = 0;
    return (0);
}

int animate_gem_end(game_t *g, int i, float minus, sfTime time)
{
    while (i < 401) {
        g->lay.y[i] += 6;
        if (g->lay.scale >= 0)
            g->lay.scale[i] = g->lay.scale[i] - minus;
        if (i == 100 || i == 200 || i == 300)
            g->lay.scale[i] -= 0.10;
        if (g->lay.scale[i] >= 0)
            sfSprite_setScale(g->lay.gem[i].sprite,
            set_pos(g->lay.scale[i], g->lay.scale[i]));
        sfSprite_setPosition(g->lay.gem[i].sprite,
        set_pos(g->lay.x[i], g->lay.y[i]));
        i++;
    }
    sfClock_restart(g->lay.clock);
    return (0);
}

int loop_set_color_end(game_t *g)
{
    switch (g->lay.color) {
        case (3):
            sfRectangleShape_setFillColor(g->lay.empty_bar, sfBlue);
            g->lay.color += 1;
            break;
        case (4):
            sfRectangleShape_setFillColor(g->lay.empty_bar, sfCyan);
            g->lay.color += 1;
            break;
        case (5):
            sfRectangleShape_setFillColor(g->lay.empty_bar, sfGreen);
            g->lay.color = 0;
            break;
    }
}
