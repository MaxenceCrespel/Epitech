/*
** EPITECH PROJECT, 2022
** start_intro_game.c
** File description:
** Function to display intro game.
*/

#include "my.h"

char *str_mod(game_t *g, char *str, int i)
{
    int x = 0;
    int length = my_strlen(str);
    char *tmp = malloc(sizeof(char) * (i + 2));

    if (str == NULL)
        return (NULL);
    while (x <= i) {
        tmp[x] = str[x];
        x++;
    }
    tmp[x] = '\0';
    return (tmp);
}

int animate_text(game_t *g, char *str)
{
    sfTime time = sfClock_getElapsedTime(g->writer.clock);
    char *font = "assets/fonts/ANY.ttf";
    int length = my_strlen(str);
    char *tmp = NULL;

    if (sfTime_asMilliseconds(time) >= 20) {
        tmp = str_mod(g, str, g->writer.x);
        g->writer.text = init_text(font, 30, set_pos(300, 800), tmp);
        g->writer.x++;
        sfClock_restart(g->writer.clock);
    }
    if (g->writer.x == length)
        g->writer.status = 1;
    return (0);
}

int init_start_intro(game_t *g)
{
    g->intro.clock = sfClock_create();
    g->intro.text = init_text("assets/fonts/ANY.ttf",
    33, set_pos(830, 700), "PRESS TO START\n");
    g->intro.status = 0;
}

int blinking_text(game_t *g)
{
    sfTime time = sfClock_getElapsedTime(g->intro.clock);

    if (sfTime_asMilliseconds(time) >= 300) {
        if (g->intro.status == 0)
            g->intro.status = 1;
        else
            g->intro.status = 0;
        sfClock_restart(g->intro.clock);
    }
}

void draw_start_intro(game_t *g)
{
    sfRenderWindow_drawSprite(g->window, g->menu.bg.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->menu.vamp.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->menu.logo.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->menu.pers2.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->menu.pers.sprite, NULL);
    blinking_text(g);
    if (g->intro.status == 0)
        sfRenderWindow_drawText(g->window, g->intro.text.text, NULL);
}
