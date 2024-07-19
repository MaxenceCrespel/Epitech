/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** Main ftrace.
*/

#include "ftrace.h"

int helper(void)
{
    printf("USAGE: ftrace <command>\n");
    return (0);
}

int main(int args, char **av, char **env)
{
    if (args == 2 && (!strcmp(av[1], "-h") || !strcmp(av[1], "--help")))
        return (helper());
    if (args == 2)
        return (my_ftrace(av[1], env, av));
    return (0);
}
