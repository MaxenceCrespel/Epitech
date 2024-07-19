/*
** EPITECH PROJECT, 2022
** my_free.c
** File description:
** My free malloc.
*/

#include "../include/my.h"

void free_array(char **array)
{
    int i = 0;

    while (array[i]) {
        my_free(array[i]);
        i++;
    }
    my_free(array);
}

void free_triple_array(char ***array)
{
    int z = 0;

    while (array[z]) {
        free_array(array[z]);
        z++;
    }
    my_free(array);
}

int my_free(void *ptr)
{
    if (ptr == NULL)
        return (0);
    free(ptr);
    return (0);
}
