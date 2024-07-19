/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** exit_builtin
*/

#include "../include/my.h"

void exit_command(char **arguments, char **env)
{
    int exit_value;

    write(2, "exit\n", 5);
    if (arguments[1] != NULL)
        exit_value = my_atoi(arguments[1]);
    else
        exit_value = 0;
    free_double(arguments);
    free_double(env);
    exit(exit_value);
}
