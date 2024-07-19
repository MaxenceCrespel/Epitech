/*
** EPITECH PROJECT, 2023
** retrieve_symbol.c
** File description:
** Retrieve symbols.
*/

#include "ftrace.h"

int init_info_tab_64(ftrace_t *ft, Elf64_Shdr *shdr, size_t i, void *buff)
{
    Elf64_Sym *symbol = (Elf64_Sym *)(buff + shdr[i].sh_offset);
    char *str = (char *)shdr[shdr[i].sh_link].sh_offset;

    for (size_t x = 0; x < shdr[i].sh_size / shdr[i].sh_entsize; x++) {
        char *name = (char *)(uintptr_t)buff + (uintptr_t)str + symbol->st_name;
        if (strcmp(name, "") != 0 && symbol->st_info != STT_FILE) {
            ft->length += 1;
        }
        symbol++;
    }
    return (0);
}

void init_struct_64(ftrace_t *ft, Elf64_Ehdr *ehdr, Elf64_Shdr *shdr, void *b)
{
    ft->length = 0;
    ft->idx = 0;

    for (size_t i = 0; i < ehdr->e_shnum; i++) {
        if (shdr[i].sh_type == SHT_SYMTAB) {
            init_info_tab_64(ft, shdr, i, b);
        }
    }
    ft->info = malloc(sizeof(info_t) * ft->length + 1);
}

void save_value_64(ftrace_t *ft, Elf64_Sym *sym, char *name)
{
    if (strcmp(name, "") != 0 && sym->st_info != STT_FILE) {
        ft->info[ft->idx].name = strdup(name);
        ft->info[ft->idx].is_undef = false;
        if (sym->st_value == 0 && sym->st_shndx == SHN_UNDEF)
            ft->info[ft->idx].is_undef = true;
        else
            ft->info[ft->idx].st_value64 = sym->st_value;
        ft->idx += 1;
    }
}

int fill_struct_nm_64(ftrace_t *ft, Elf64_Shdr *shdr, size_t i, void *buff)
{
    char *strs = (char *)shdr[shdr[i].sh_link].sh_offset;
    Elf64_Sym *sym = (Elf64_Sym *)(buff + shdr[i].sh_offset);

    for (size_t x = 0; x < shdr[i].sh_size / shdr[i].sh_entsize; x++) {
        char *name = (char *)(uintptr_t)buff + (uintptr_t)strs + sym->st_name;
        save_value_64(ft, sym, name);
        sym++;
    }
    return (0);
}

int initialize_list(ftrace_t *ft, char **av)
{
    struct stat statbuf;

    stat(av[1], &statbuf);
    handling_file(av[1], statbuf);
    int fd = open(av[1], O_RDONLY);
    void *buffer = mmap(0, statbuf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    Elf64_Ehdr *ehdr = (Elf64_Ehdr *)buffer;
    Elf64_Shdr *shdr = (Elf64_Shdr *)(buffer + ehdr->e_shoff);

    init_struct_64(ft, ehdr, shdr, buffer);
    for (size_t i = 0; i < ehdr->e_shnum; i++) {
        if (shdr[i].sh_type == SHT_SYMTAB)
            fill_struct_nm_64(ft, shdr, i, buffer);
    }
    ft->ret = malloc(ft->length * sizeof(char*));
    return (0);
}
