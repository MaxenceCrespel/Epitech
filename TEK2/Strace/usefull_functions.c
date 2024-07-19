/*
** EPITECH PROJECT, 2023
** strace2
** File description:
** usefull_functions
*/

#include "strace.h"

bool is_syscall(unsigned short instr_code)
{
    return instr_code == 0x050F;
}
