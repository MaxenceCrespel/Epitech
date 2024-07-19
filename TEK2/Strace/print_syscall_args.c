/*
** EPITECH PROJECT, 2023
** strace2
** File description:
** print_syscall_args
*/

#include "strace.h"

void print_syscall_arg(pid_t child, int index, int option, enum e_arg_type type)
{
    int regs[6] = {RDI, RSI, RDX, R10, R8, R9};
    int offset = sizeof(unsigned long) * regs[index];
    unsigned long value = ptrace(PTRACE_PEEKUSER, child, offset);

    print_arg(child, value, option, type);
}

void print_syscall_args_list(pid_t child, t_entry *entry, int option)
{
    for (int i = 0; i < entry->nb_args; i++) {
        enum e_arg_type type = entry->args_value[i];
        print_syscall_arg(child, i, option, type);
        if (i != entry->nb_args - 1)
            fprintf(stderr, ", ");
    }
}

void print_syscall_arg_null(int nb_args, pid_t child, int option)
{
    for (int i = 0; i < nb_args; i++) {
        print_syscall_arg(child, i, option, PTR);
        if (i != nb_args - 1)
            fprintf(stderr, ", ");
    }
}

void print_syscall_args(pid_t child, int num, int option)
{
    t_entry *entry = get_syscall_entry(num);
    int nb_args = (entry != NULL) ? entry->nb_args : 6;

    if (entry != NULL)
        print_syscall_args_list(child, entry, option);
    else
        print_syscall_arg_null(nb_args, child, option);
}
