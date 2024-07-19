/*
** EPITECH PROJECT, 2022
** init_monster3.c
** File description:
** Init monster.
*/

#include "my.h"

monster_t create_monster_sev(game_t *g)
{
    monster_t list;
    sfTexture *img = sfTexture_createFromFile("assets/img/enemies.png", NULL);
    list.sprite = set_sprite(img, set_pos(300, 300), set_pos(4, 4));
    sfSprite_setOrigin(list.sprite.sprite, set_pos(23, 0));
    list.life = 1400;
    list.speed = 3.6;
    list.damage = 60;
    list.rect = malloc(sizeof(sfIntRect) * 4);
    list.rect[0] = pos_rect(130, 1830, 44, 56);
    sfSprite_setTextureRect(list.sprite.sprite, list.rect[0]);
    list.rect[1] = pos_rect(191, 1607, 45, 54);
    list.rect[2] = pos_rect(595, 1325, 44, 51);
    list.rect[3] = pos_rect(509, 1475, 44, 48);
    return list;
}

monster_t create_monster_heig(game_t *g)
{
    monster_t list;
    sfTexture *img = sfTexture_createFromFile("assets/img/enemies.png", NULL);
    list.sprite = set_sprite(img, set_pos(300, 300), set_pos(5, 5));
    sfSprite_setOrigin(list.sprite.sprite, set_pos(23, 0));
    list.life = 1200;
    list.speed = 2.8;
    list.damage = 75;
    list.rect = malloc(sizeof(sfIntRect) * 4);
    list.rect[0] = pos_rect(662, 842, 32, 33);
    sfSprite_setTextureRect(list.sprite.sprite, list.rect[0]);
    list.rect[1] = pos_rect(1104, 513, 32, 32);
    list.rect[2] = pos_rect(930, 434, 32, 34);
    list.rect[3] = pos_rect(1104, 513, 32, 32);
    return list;
}

monster_t *create_monster(game_t *g)
{
    monster_t *list = malloc(sizeof(monster_t) * 8);
    list[0] = create_monster_un(g);
    list[1] = create_monster_two(g);
    list[2] = create_monster_tree(g);
    list[3] = create_monster_four(g);
    list[4] = create_monster_five(g);
    list[5] = create_monster_six(g);
    list[6] = create_monster_sev(g);
    list[7] = create_monster_heig(g);
    return list;
}

sfVector2f random_pos_item(void)
{
    sfVector2f pos;
    pos.x = (rand() % 15000) - 7500;
    pos.y = (rand() % 13000) - 6500;
    if (pos.x >= 0 && pos.x < 1920 && pos.y >= 0 && pos.y < 1080)
        return random_pos_item();
    return pos;
}

list_it *init_item(game_t *g)
{
    list_it *list = malloc(sizeof(list_it) * 6);
    sfTexture *bg = sfTexture_createFromFile("assets/img/items.png", NULL);
    list[0].img = set_sprite_rect(bg, random_pos_item(), set_pos(3, 3),
    pos_rect(514, 1, 16, 16));
    list[1].img = set_sprite_rect(bg, random_pos_item(), set_pos(1, 1),
    pos_rect(66, 2, 30, 53));
    list[2].img = set_sprite_rect(bg, random_pos_item(), set_pos(3, 3),
    pos_rect(199, 42, 14, 12));
    list[3].img = set_sprite_rect(bg, random_pos_item(), set_pos(3, 3),
    pos_rect(386, 1, 21, 31));
    list[4].img = set_sprite_rect(bg, random_pos_item(), set_pos(3, 3),
    pos_rect(515, 19, 13, 14));
    list[5].img = set_sprite_rect(bg, random_pos_item(), set_pos(3, 3),
    pos_rect(547, 35, 12, 12));
    for (int i = 0; i < 6; i++)
        list[i].status = 1;
    return list;
}
