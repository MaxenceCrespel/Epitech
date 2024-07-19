/*
** EPITECH PROJECT, 2022
** my_r
** File description:
** r
*/

#include "include/my_printf.h"

int stop(char c, char *c_stop)
{
    for (int i = 0; c_stop[i]; i++)
        if (c == c_stop[i])
            return (1);
    return (0);
}

int end(char *str, int i, char *c_stop)
{
    if (stop(str[i], c_stop)) {
        for (; stop(str[i], c_stop); i++);
        i--;
    }
    return (i);
}

int len_word(char *str, int i, char *c_stop)
{
    int len = 0;
    for (; !stop(str[i], c_stop) && str[i]; i++, len++);
    return len;
}

int len_str(char *str, char *c_stop)
{
    int nb = 1;
    for (int i = 0; str[i]; i++, nb++)
        i = end(str, i, c_stop);
    return nb;
}

char **my_str_to_word_array(char *str, char *c_stop)
{
    int i = 0;
    int x = 0;
    int y = 0;
    char **list = malloc(sizeof(char *) * (len_str(str, c_stop) + 1));
    if (list == NULL)
        return NULL;
    for (; str[i]; y++) {
        for (i = i, x = 0; str[i] && stop(str[i], c_stop); i++);
        list[y] = my_malloc(len_word(str, i, c_stop));
        for (i = i; str[i] && !stop(str[i], c_stop); i++, x++)
            list[y][x] = str[i];
        list[y][x] = '\0';
        for (i = i, x = 0; str[i] && stop(str[i], c_stop); i++);
    }
    list[y] = NULL;
    return list;
}
