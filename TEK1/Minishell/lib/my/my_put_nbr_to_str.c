/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_put_nbr_to_str
*/

#include "../../include/my.h"

void put_nb_to_str_ter(char *str, char *nb, int i, int b)
{
    while (str[i] != ' ')
        i++;
    for (; nb[b] != '\0'; b++, i++)
        str[i] = nb[b];
    i = 0;
    while (str[i] != ' ')
        i++;
    while (str[i] == ' ')
        move_left(str, i);
}

int put_nb_to_str_bis(char *str, int i, char operator)
{
    while (str[i] != operator)
        i++;
    i--;
    while (str[i] >= '0' && str[i] <= '9')
        i--;
    return i;
}

void put_nb_to_str(char *str, char *nb, char operator)
{
    int i = put_nb_to_str_bis(str, 0, operator);
    int start = i + 1;
    int end = 0;

    if (str[start - 1] == '-')
        start -= 1;
    while (str[i] != operator)
        i++;
    i++;
    if (str[i] == '-')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    end = i;
    while (start < end) {
        str[start] = ' ';
        start++;
    }
    put_nb_to_str_ter(str, nb, 0, 0);
}
