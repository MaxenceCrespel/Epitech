/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** minishell
*/

#include "../include/my.h"

void print_path(void)
{
    char buff[236];

    my_printf("[%s]$ ", getcwd(buff, sizeof(buff)));
}

char *read_line(void)
{
    char *str = NULL;
    size_t l;

    if (isatty(STDIN_FILENO))
        print_path();
    if (getline(&str, &l, stdin) == EOF) {
        if (isatty(STDIN_FILENO))
            write(2, "exit\n", 5);
        exit(0);
    }
    return str;
}

int check_existence(char **args, char **env)
{
    int line = 0;
    int i = 0;
    char *check_line;
    int a = 0;

    for (; env[line] != NULL; line++) {
        for (i = 0; env[line][i] != '='; i++);
        check_line = malloc(sizeof(char) * i + 2);
        for (a = 0; a < i; a++)
            check_line[a] = env[line][a];
        check_line[a] = '\0';
        if (my_strcmp(check_line, args[1]) == 1)
            return line;
        free(check_line);
        a = 0;
    }
    return (-1);
}

void minishell(char **env_cpy)
{
    char *line;

    while (1) {
        line = read_line();
        line = clean_str(line);
        env_cpy = semicolons(line, env_cpy);
        free(line);
    }
}
