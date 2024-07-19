/*
** EPITECH PROJECT, 2023
** error_handling.c
** File description:
** error.
*/

#include "ftrace.h"

int perror_handling(char *err)
{
    perror(err);
    return (84);
}
