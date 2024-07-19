/*
** EPITECH PROJECT, 2022
** createmap
** File description:
** rpg
*/

#include "my.h"

void init_map(map *m, char *maps)
{
    m->fd = fopen(maps, "r");
    m->pos.x = (-5) * 2048;
    m->pos.y = (-5) * 2048;
    m->rect = pos_rect(0, 0, 1024, 1024);
    m->line = NULL;
    m->len = 0;
    m->nline = 0;
}

int complete_sprite(add_sprite **actual, add_sprite *next_sprite\
, add_sprite *last)
{
    if (*actual == NULL) {
        *actual = next_sprite;
        return 1;
    }
    while (last->next)
        last = last->next;
    last->next = next_sprite;
    return 0;
}

void put_sprite(char *file, add_sprite **actual\
, sfVector2f pos, sfIntRect rect)
{
    add_sprite *next_sprite = malloc(sizeof(add_sprite));
    sfSprite *sprite = sfSprite_create();
    next_sprite->texture = sfTexture_createFromFile(file, NULL);
    next_sprite->sprite = sprite;
    next_sprite->position = pos;
    next_sprite->rect = rect;
    next_sprite->next = NULL;
    sfVector2f scale = {2, 2};
    sfSprite_setScale(next_sprite->sprite, scale);
    sfSprite_setTexture(next_sprite->sprite, next_sprite->texture, sfTrue);
    sfSprite_setPosition(next_sprite->sprite, pos);
    sfSprite_setTextureRect(next_sprite->sprite, rect);
    add_sprite *last = *actual;
    if (complete_sprite(actual, next_sprite, last) == 1)
        return;
}

void create_map_nline(map *m, game_t *game, int i)
{
    char *p[] = {"assets/img/bg_forest.png", "assets/img/bg_green.png"\
    , "assets/img/bg_molise.png"};

    if (m->line[i] == '1')
        put_sprite(p[0], &game->start.map, m->pos, m->rect);
    if (m->line[i] == '2')
        put_sprite(p[1], &game->start.map, m->pos, m->rect);
    if (m->line[i] == '3')
        put_sprite(p[2], &game->start.map, m->pos, m->rect);
    m->pos.x += 2048;
}

void create_map(game_t *game)
{
    char *maps = "map";
    game->start.map = NULL;
    map *m = malloc(sizeof(map));
    init_map(m, maps);
    while ((getline(&m->line, &m->len, m->fd)) != -1) {
        for (int i = 0; m->line[i]; i++)
            create_map_nline(m, game, i);
        m->pos.x = (-5) * 2048;
        m->pos.y += 2048;
        m->nline += 1;
    }
    fclose(m->fd);
    free(m);
}
