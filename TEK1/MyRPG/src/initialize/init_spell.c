/*
** EPITECH PROJECT, 2022
** init_spell.c
** File description:
** Init spell.
*/

#include "my.h"

stat_cara_t *create_stat_perso(game_t *g)
{
    stat_cara_t *stat = malloc(sizeof(stat_cara_t) * 6);
    stat[0] = stat_cara_un();
    stat[1] = stat_cara_two();
    stat[2] = stat_cara_three();
    stat[3] = stat_cara_four();
    stat[4] = stat_cara_five();
    stat[5] = stat_cara_six();
    return stat;
}

stat_attack_t create_attack_fouet(void)
{
    stat_attack_t attack;
    sfTexture *bg = sfTexture_createFromFile("assets/img/items.png", NULL);
    attack.img = set_sprite_rect(bg, set_pos(150, 150),
    set_pos(3, 3), pos_rect(350, 40, 16, 14));
    bg = sfTexture_createFromFile("assets/img/vfx.png", NULL);
    attack.vfx = set_sprite_rect(bg, set_pos(1000, 550),
    set_pos(2, 2), pos_rect(930, 259, 148, 23));
    attack.max_time = 300;
    attack.cooldown = 750;
    attack.actif = 0;
    attack.dama = 15;
    return attack;
}

stat_attack_t create_attack_fire(void)
{
    stat_attack_t attack;
    sfTexture *bg = sfTexture_createFromFile("assets/img/items.png", NULL);
    attack.img = set_sprite_rect(bg, set_pos(150, 150),
    set_pos(3, 3), pos_rect(419, 23, 17, 17));
    bg = sfTexture_createFromFile("assets/img/vfx.png", NULL);
    attack.vfx = set_sprite_rect(bg, set_pos(900, 520),
    set_pos(4, 4), pos_rect(599, 453, 21, 21));
    attack.max_time = 2800;
    attack.actif = 0;
    attack.cooldown = 1500;
    attack.dama = 30;
    return attack;
}

stat_attack_t create_attack_couteau(void)
{
    stat_attack_t attack;
    sfTexture *bg = sfTexture_createFromFile("assets/img/items.png", NULL);
    attack.img = set_sprite_rect(bg, set_pos(150, 150),
    set_pos(3, 3), pos_rect(607, 34, 18, 9));
    bg = sfTexture_createFromFile("assets/img/vfx.png", NULL);
    attack.vfx = set_sprite_rect(bg, set_pos(960, 540),
    set_pos(4, 4), pos_rect(864, 413, 16, 6));
    sfSprite_setOrigin(attack.vfx.sprite, set_pos(7, 3));
    attack.max_time = 2800;
    attack.actif = 0;
    attack.cooldown = 1000;
    attack.dama = 42;
    return attack;
}

stat_attack_t create_attack_lorel(void)
{
    stat_attack_t attack;
    sfTexture *bg = sfTexture_createFromFile("assets/img/items.png", NULL);
    attack.img = set_sprite_rect(bg, set_pos(150, 150),
    set_pos(3, 3), pos_rect(125, 30, 15, 15));
    bg = sfTexture_createFromFile("assets/img/vfx.png", NULL);
    attack.vfx = set_sprite_rect(bg, set_pos(870, 488),
    set_pos(4, 4), pos_rect(640, 378, 34, 34));
    sfSprite_setColor(attack.vfx.sprite, sfColor_fromRGBA(119, 181, 254, 230));
    attack.actif = 0;
    attack.cooldown = 5000;
    return attack;
}
