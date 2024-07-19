/*
** EPITECH PROJECT, 2023
** my_ftrace.c
** File description:
** Ftrace.
*/

#include "ftrace.h"

ftrace_t initialize_struct(char *command, char **env)
{
    ftrace_t ftrace;

    ftrace.command = strdup(command);
    ftrace.env = env;
    return (ftrace);
}

int fork_process(ftrace_t *ft, char **av)
{
    ft->pid = fork();
    if (ft->pid == -1)
        return (84);
    if (ft->pid == 0) {
        if (ptrace(PTRACE_TRACEME, 0, NULL, 0) == -1)
            return (perror_handling("ptrace"));
        if (execvp(av[1], &av[1]) == -1)
            return (perror_handling("execvp"));
    } else if (main_process(ft) != 0)
        return (84);
    return (0);
}

int my_ftrace(char *command, char **env, char **av)
{
    ftrace_t ftrace = initialize_struct(command, env);

    if (start_ftrace(&ftrace, av) == 84)
        return (84);
    return (0);
}

int start_ftrace(ftrace_t *ft, char **av)
{
    initialize_list(ft, av);
    if (fork_process(ft, av) == 84)
        return (84);
    return (0);
}
