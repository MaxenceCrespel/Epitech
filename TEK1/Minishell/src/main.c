/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/

#include "../include/my.h"

int main(int ac, char **av, char **env)
{
    ac = ac;
    av = av;
    char **env_cpy = cp_env(env);

    minishell(env_cpy);
    free_double(env_cpy);
}
