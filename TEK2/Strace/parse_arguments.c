/*
** EPITECH PROJECT, 2023
** strace2
** File description:
** parse_arguments
*/

#include "strace.h"

void handle_option_option(const char *arg, int *option)
{
    if (strcmp(arg, "-s") == 0)
        *option = 1;
}

void run_child_process(const char **av, int ac, int option)
{
    av += option + 1;
    ac -= option + 1;
    ptrace(PTRACE_TRACEME, 0, NULL, NULL);
    kill(getpid(), SIGSTOP);
    execvp(av[0], (char *const *)av);
    exit(1);
}


void handle_pid_option(const char **av, int ac, int option, pid_t *pid)
{
    pid_t pid_arg;
    if (strcmp(av[option + 1], "-p") == 0 && ac >= option + 3) {
        pid_arg = atoi(av[option + 2]);
        if (pid_arg <= 0)
            exit(84);
        *pid = (pid_t) pid_arg;
    } else {
        *pid = fork();
        sleep(1);
        if (*pid == -1)
            exit(84);
        if (*pid == 0)
            run_child_process(av, ac, option);
    }
}

void parse_arguments(int ac, const char **av, int *option, pid_t *pid)
{
    handle_option_option(av[1], option);
    handle_pid_option(av, ac, *option, pid);
}
