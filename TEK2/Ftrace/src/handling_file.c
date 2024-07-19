/*
** EPITECH PROJECT, 2023
** handling_file.c
** File description:
** Handling file.
*/

#include "ftrace.h"

bool is_elf64_incomplete(struct stat statbuf, char *filename)
{
    unsigned int ehdr_size;
    int fd = open(filename, O_RDONLY);
    void *buffer = mmap(0, statbuf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    Elf64_Ehdr *header = (Elf64_Ehdr *)buffer;

    if (header->e_ident[4] == ELFCLASS64) {
        ehdr_size = (header->e_shentsize * header->e_shnum) + header->e_shoff;
        if (statbuf.st_size != ehdr_size)
            return (true);
    }
    return (false);
}

bool is_unrecognized(char *filename)
{
    Elf64_Ehdr header;
    FILE *fp = fopen(filename, "r");

    if (fp) {
        fread(&header, sizeof(header), 1, fp);
        if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0) {
            fclose(fp);
            return (true);
        }
        fclose(fp);
        return (false);
    }
    return (true);
}

int handling_file(char *filename, struct stat statbuf)
{
    if (S_ISDIR(statbuf.st_mode) == true) {
        fprintf(stderr, "ftrace: Warning: '%s' is a directory\n", filename);
        exit (84);
    }
    if (access(filename, F_OK) == -1) {
        fprintf(stderr, "ftrace: '%s': No such file\n", filename);
        exit (84);
    }
    if (is_unrecognized(filename) == true) {
        fprintf(stderr, "ftrace: %s: file format not recognized\n", filename);
        exit (84);
    }
    if (is_elf64_incomplete(statbuf, filename) == true) {
        fprintf(stderr, "ftrace: %s: file format not recognized\n", filename);
        exit (84);
    }
    return (0);
}
