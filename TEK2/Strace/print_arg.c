/*
** EPITECH PROJECT, 2023
** strace2
** File description:
** print_arg
*/

#include "strace.h"

void print_str_arg(pid_t child, unsigned long arg)
{
    char *str = get_string(child, arg);
    int len = strnlen(str, 32);

    fprintf(stderr, "\"");
    for (int i = 0; i < len; i++)
        fprintf(stderr, isprint(str[i]) ? "%c" : "\\%o", str[i]);
    if (len >= 32)
        fprintf(stderr, "\"...");
    else
        fprintf(stderr, "\"");
    free(str);
}

void print_arg(pid_t child, unsigned long arg, int option,
enum e_arg_type type)
{
    switch(type) {
        case INT:
            fprintf(stderr, "%lld", arg);
            break;
        case STR:
            print_str_arg(child, arg);
            break;
        case PTR:
            fprintf(stderr, option ? (arg ? "0x%llx" : "NULL") : "0x%llx", arg);
            break;
    }
}
