/*
** EPITECH PROJECT, 2022
** langage.c
** File description:
** functions to change the langage
*/

#include "my.h"

void change_language(game_t *g)
{
    int y = 150;
    int e = 0;
    int x = 0;
    char *ttf = "assets/fonts/ANY.ttf";
    for (int i = 0; i < 11; i++) {
        sfText_setString(g->power_up.list[i].name.text,
        langage[g->option.langage][0][i]);
    }
    for (int i = 0; i != 12; i++) {
        sfText_setString(g->reaper.speak[i].text,
        langage[g->option.langage][5][i]);
    }
    free(g->chose_attack);
    g->chose_attack = create_chose_attack(g);
}

void event_key_three(game_t *g, sfEvent event)
{
    if (event.key.code == sfKeyL) {
        if (g->option.langage == 0)
            g->option.langage = 1;
        else
            g->option.langage = 0;
        change_language(g);
    }
}
