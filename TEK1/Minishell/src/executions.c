/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** exec_command
*/

#include "../include/my.h"

int exists(const char *fname)
{
    int fd;
    if ((fd = open(fname, O_RDONLY)) == -1)
        return 1;
    return 0;
}

int exec_n_builtin(char *new_path, char **arguments, char **env)
{
    pid_t pid;
    pid_t wpid;
    int status;

    if (new_path == NULL) {
        write(2, arguments[0], my_strlen(arguments[0]));
        write(2, ": Command not found.\n", 21);
        return 84;
    }
    pid = fork();
    if (pid == 0) {
        execve(new_path, arguments, env);
        exit(EXIT_FAILURE);
    } else
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
    return 1;
}

int execute(char **arguments, char **env)
{
    char *new_path;
    int return_value = 0;

    new_path = get_path(arguments, env);
    return_value = exec_n_builtin(new_path, arguments, env);
    free(new_path);
    return (return_value);
}
