/*
** EPITECH PROJECT, 2022
** init_save2.c
** File description:
** Init save, open & stock file save.
*/

#include "my.h"

int verrif_len_line_save(char *cmd, game_t *g)
{
    char **verif = NULL;
    int e;
    verif = my_str_to_word_array(cmd, " ");
    if (verif == NULL)
        return (-1);
    for (e = 0; verif[e]; e++);
    if (e != 3 || !my_str_isnum(verif[2])) {
        free_array(verif);
        return (-1);
    }
    e = my_atoi(verif[2]);
    free_array(verif);
    return e;
}

void set_list_in_save(game_t *g, int list[])
{
    int i = 0;
    g->save.i_or = list[i++];
    int len = ((my_strlen(my_itoa(g->save.i_or)) - 1) * 25);
    g->save.t_or = init_text("assets/fonts/KO.ttf", 40,
    set_pos(1050 - len, 22), my_itoa(g->save.i_or));
    g->save.max_life = list[i++];
    g->save.recov = list[i++];
    g->save.ms = list[i++];
    g->save.armor = list[i++];
    g->save.area = list[i++];
    g->save.speed = list[i++];
    g->save.cooldown = list[i++];
    g->save.pene = list[i++];
    g->save.duration = list[i++];
    g->save.magnet = list[i++];
    g->save.growth = list[i++];
}

void get_perso(game_t *g, char *str)
{
    char **split = my_str_to_word_array(str, " ");
    g->save.perso = malloc(sizeof(int) * 6);
    for (int i = 0; i < 6; i++) {
        if (!my_strcmp(split[i], "1"))
            g->save.perso[i] = 1;
        else
            g->save.perso[i] = 0;
    }
}

void verif_file(char *buffer, game_t *g)
{
    int line = 0;
    char **tab_save = my_str_to_word_array(buffer, "\n");
    for (int i = 0; buffer[i]; i++)
        line = (buffer[i] == '\n' ? line + 1 : line);
    if (line != 12)
        return init_save(g);
    int list[11];
    for (int i = 0; i < 12; i++) {
        list[i] = verrif_len_line_save(tab_save[i], g);
        if (list[i] == -1)
            return init_save(g);
    }
    set_list_in_save(g, list);
    get_perso(g, tab_save[12]);
    free_array(tab_save);
}

void get_save(game_t *g)
{
    struct stat stats;
    int fd = open(".save", O_RDONLY);
    char *buffer;

    if (fd == -1 || (stat(".save", &stats) == -1))
        return init_save(g);
    buffer = malloc(sizeof(char) * (stats.st_size + 1));
    buffer[stats.st_size] = '\0';
    if (read(fd, buffer, stats.st_size) == -1) {
        free(buffer);
        return;
    }
    close(fd);
    verif_file(buffer, g);
    free(buffer);
}
