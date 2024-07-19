/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_strcat
*/

#include "../../include/my.h"

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    char *new;

    if (dest == NULL)
        return (src);
    if (src == NULL)
        return (dest);
    new = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    while (dest[i] != '\0') {
        new[i] = dest[i];
        i++;
    }
    while (src[j] != '\0')
        new[i++] = src[j++];
    new[i] = '\0';
    return (new);
}
