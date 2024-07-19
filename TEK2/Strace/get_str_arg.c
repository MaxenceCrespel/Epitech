/*
** EPITECH PROJECT, 2023
** strace2
** File description:
** get_str_arg
*/

#include "strace.h"

unsigned long read_memory(pid_t child, unsigned long addr)
{
    unsigned long tmp;
    tmp = ptrace(PTRACE_PEEKDATA, child, addr);
    return tmp;
}

void realloc_val(char **val_ptr, int *val_capacity_ptr, int val_len)
{
    const int chunk_size = 1024;
    if (val_len + chunk_size >= *val_capacity_ptr) {
        *val_capacity_ptr = (*val_capacity_ptr == 0) ? chunk_size : *val_capacity_ptr * 2;
        *val_ptr = (char *)realloc(*val_ptr, *val_capacity_ptr);
    }
}

unsigned long read_chunk(pid_t child, unsigned long chunk_addr)
{
    unsigned long chunk_val = read_memory(child, chunk_addr);
    return chunk_val;
}

int append_chunk_to_val(char *val, int val_len, unsigned long chunk_val)
{
    char *chunk_ptr = (char *)&chunk_val;
    for (int i = 0; i < sizeof(chunk_val); i++) {
        val[val_len] = chunk_ptr[i];
        val_len++;
    }
    return val_len;
}

char *get_string(pid_t child, unsigned long addr)
{
    char *val = NULL;
    int val_len = 0;
    int val_capacity = 0;
    unsigned long chunk_addr = 0;
    unsigned long chunk_val = 0;

    while (true) {
        realloc_val(&val, &val_capacity, val_len);
        chunk_addr = addr + val_len;
        chunk_val = read_chunk(child, chunk_addr);
        if (errno != 0 || chunk_val == 0) {
            val[val_len] = '\0';
            break;
        }
        val_len = append_chunk_to_val(val, val_len, chunk_val);
    }
    return val;
}
