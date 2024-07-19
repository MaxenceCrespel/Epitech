/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** rpg
*/

#include "my.h"

int main(int ac, char **av)
{
    game_t *g = malloc(sizeof(game_t));

    if (g == NULL)
        return (84);
    if (ac == 2 && !my_strcmp(av[1], "-h"))
        return (display_help());
    init_game(g);
    while (sfRenderWindow_isOpen(g->window)) {
        launch(g);
    }
    write_save(g);
    write_achiev(g);
    my_destroy_all(g);
    my_free(g);
    return (0);
}
