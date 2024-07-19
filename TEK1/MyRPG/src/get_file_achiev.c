/*
** EPITECH PROJECT, 2022
** get file achiev
** File description:
** rpg
*/

#include "my.h"

void init_save_achiev(achive_t *list)
{
    for (int i = 0; i < 10; i++)
        list[i].actu = 0;
}

int get_achiev_actu(char *cmd, game_t *g)
{
    int e;
    if (cmd == NULL)
        return (-1);
    if (!my_str_isnum(cmd))
        return (-1);
    e = my_atoi(cmd);
    return e;
}

void verif_file_achiev(char *buffer, game_t *g, achive_t *list)
{
    int line = 0;
    char **tab_save = my_str_to_word_array(buffer, "\n");
    for (int i = 0; buffer[i]; i++)
        line = (buffer[i] == '\n' ? line + 1 : line);
    if (line != 10)
        return init_save_achiev(list);
    for (int i = 0; i < 10; i++) {
        list[i].actu = get_achiev_actu(tab_save[i], g);
        if (list[i].actu == -1)
            return init_save_achiev(list);
    }
    free_array(tab_save);
}
