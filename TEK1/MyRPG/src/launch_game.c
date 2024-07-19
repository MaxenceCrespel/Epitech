/*
** EPITECH PROJECT, 2022
** launch_game.c
** File description:
** Launch game.
*/

#include "my.h"

int draw_option_mod(game_t *g)
{
    sfSprite_setPosition(g->option.back.sprite, set_pos(1170, 15));
    sfSprite_setPosition(g->option.quit.sprite, set_pos(528, 15));
    sfText_setPosition(g->option.t_quit.text, set_pos(570, 20));
    sfText_setPosition(g->option.t_back.text, set_pos(1212, 20));
    if (g->old_scene == 1) {
        sfSprite_setPosition(g->option.back.sprite, set_pos(1170, 55));
        sfSprite_setPosition(g->option.quit.sprite, set_pos(528, 55));
        sfText_setPosition(g->option.t_quit.text, set_pos(570, 60));
        sfText_setPosition(g->option.t_back.text, set_pos(1212, 60));
    }
}

void launch(game_t *g)
{
    sfEvent event;
    draw_window(g);
    g->mouse = sfMouse_getPositionRenderWindow(g->window);
    animate_buttons(g);
    while (sfRenderWindow_pollEvent(g->window, &event))
        my_event(g, event);
    conditions_scene(g);
}

int write_nb_in_save(game_t *g, int nb)
{
    switch (nb) {
        case 0 : return g->save.i_or;
        case 1 : return g->save.max_life;
        case 2 : return g->save.recov;
        case 3 : return g->save.ms;
        case 4 : return g->save.armor;
        case 5 : return g->save.area;
        case 6 : return g->save.speed;
        case 7 : return g->save.cooldown;
        case 8 : return g->save.pene;
        case 9 : return g->save.duration;
        case 10 : return g->save.magnet;
        case 11 : return g->save.growth;
    }
    return 0;
}

void write_save(game_t *g)
{
    FILE *fd;
    remove(".save");
    fd = fopen(".save", "w");
    char *nb = NULL;
    if (fd == NULL)
        return;
    for (int i = 0; i < 12; i++) {
        fwrite(NAME_SAVE_ENG[i], 1, my_strlen(NAME_SAVE_ENG[i]), fd);
        fwrite(" = ", 1, 3, fd);
        nb = my_itoa(write_nb_in_save(g, i));
        fwrite(nb, 1, my_strlen(nb), fd);
        fwrite("\n", 1, 1, fd);
        free(nb);
    }
    for (int i = 0; i < 6; i++) {
        nb = my_itoa(g->save.perso[i]);
        fwrite(nb, 1, my_strlen(nb), fd);
        fwrite(" ", 1, 1, fd);
    }
    fclose(fd);
}

void write_achiev(game_t *g)
{
    FILE *fd;
    remove(".achiev");
    fd = fopen(".achiev", "w");
    char *nb = NULL;
    if (fd == NULL)
        return;
    for (int i = 0; i < 10; i++) {
        nb = my_itoa(g->achiev[i].actu);
        fwrite(nb, 1, my_strlen(nb), fd);
        fwrite("\n", 1, 1, fd);
        free(nb);
    }
    fclose(fd);
}
