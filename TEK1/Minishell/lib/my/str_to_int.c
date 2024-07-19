/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** str_to_int
*/

int str_to_int(char *str, int start, int end)
{
    int value = 0;

    while (start < end) {
        value = value * 10 + (str[start] - 48);
        start++;
    }
    return value;
}
