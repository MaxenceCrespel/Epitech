/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** clean_str
*/

#include "../include/my.h"

int clean_end(char *str)
{
    int end = 0;

    for (end = my_strlen(str) - 1; str[end] == ' '
    || str[end] == '\t' || str[end] == '\n'; end--);
    return end;
}

char *clean_str(char *str)
{
    int i = 0;
    int j = 0;
    int end = clean_end(str);
    char *dest = malloc(sizeof(char) * my_strlen(str) + 1);

    for (; str[i] == ' ' || str[i] == '\t'; i++);
    while (i <= end) {
        if (str[i] != ' ' || str[i + 1] == ' '
        || str[i] != '\t') {
            dest[j] = str[i];
            i++;
            j++;
        }
        for (; (str[i] == ' ' && str[i + 1] == ' ')
            || str[i] == '\t'; i++);
    }
    dest[j] = '\0';
    return dest;
}
