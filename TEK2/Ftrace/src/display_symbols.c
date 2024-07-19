/*
** EPITECH PROJECT, 2023
** display_symbols.c
** File description:
** Display symbols.
*/

#include "ftrace.h"

void put_ret_in_tab(ftrace_t *ft, char *name)
{
    int index;
    for (index = 0; ft->ret[index] != NULL; index++);
    ft->ret[index] = strdup(name);
}

void print_entry(ftrace_t *ft, struct user_regs_struct regs)
{
    for (size_t i = 0; i < ft->length ; i++) {
        if (ft->info[i].st_value64 == regs.rip) {
            printf("Entering function %s at 0x%lx\n",
            ft->info[i].name, ft->info[i].st_value64);
            put_ret_in_tab(ft, ft->info[i].name);
        }
    }
}

int print_symbol(ftrace_t *ft)
{
    struct user_regs_struct regs;
    unsigned mem = 0;
    unsigned char flag;
    int status = 0;
    if (ptrace(PTRACE_SINGLESTEP, ft->pid, NULL, NULL) == -1)
        return (perror_handling("ptrace"));
    wait(&status);
    if (WIFEXITED(status))
        return 84;
    if (ptrace(PTRACE_GETREGS, ft->pid, NULL, &regs) == -1)
        return (perror_handling("ptrace"));
    mem = ptrace(PTRACE_PEEKTEXT, ft->pid, regs.rip, NULL);
    flag = ((unsigned)0xFF00 & mem) >> 8;
    if (flag == 0x48)
        print_entry(ft, regs);
    return (0);
}

int print_ret(ftrace_t *ft)
{
    int index = 0;
    for (index = 0; ft->ret[index] != NULL; index++);
    if (index != 0)
        index = index - 1;
    if (ft->ret[index]) {
        printf("Leaving function %s\n", ft->ret[index]);
        free(ft->ret[index]);
        ft->ret[index] = NULL;
    }
    return (0);
}
