/*
** EPITECH PROJECT, 2022
** init_start2
** File description:
** rpg
*/

#include "my.h"

int stat_calc(float pers, int save, int pour)
{
    int nb = pers;
    nb += ((pers / 100) * (pour * save));
    if (nb == 0)
        nb = 1;
    return nb;
}

void add_stat_save(game_t *g, stat_cara_t *perso)
{
    perso->area = stat_calc((float)perso->area, g->save.area, 5);
    perso->armor += g->save.armor;
    perso->cooldown = stat_calc((float)perso->cooldown, g->save.cooldown, 3);
    perso->magnet = stat_calc((float)perso->magnet, g->save.magnet, 25);
    perso->max_life = stat_calc((float)perso->max_life, g->save.max_life, 10);
    perso->ms = stat_calc((float)perso->ms, g->save.ms, 10);
    perso->pene += g->save.pene;
    perso->recov += g->save.recov;
    perso->speed = stat_calc((float)perso->speed, g->save.speed, 10);
    perso->life = perso->max_life;
    perso->growth += g->save.growth * 3;
    perso->duration += stat_calc((float)perso->duration, g->save.duration, 15);
}

slot_t *create_slot_attack(game_t *g, int nb)
{
    slot_t *attack = malloc(sizeof(slot_t) * 7);
    attack[6].att.img.sprite = NULL;
    for (int i = 0; i < 6; i++) {
        attack[i].att.img.sprite = NULL;
        attack[i].lvl = 0;
        attack[i].status = -1;
        attack[i].have = -1;
    }
    attack[0].att = g->stat_attack[nb];
    attack[0].lvl = 1;
    attack[0].clock = sfClock_create();
    attack[0].status = nb;
    attack[0].have = 1;
    sfSprite_setPosition(attack[0].att.img.sprite,
    set_pos(735 + (0 * 80), 830));
    return attack;
}

void create_slot_empty(game_t *g, int nb)
{
    sfTexture *bg = sfTexture_createFromFile("assets/img/UI.png", NULL);
    g->start.inv.empty_s = set_sprite_rect(bg, set_pos(720, 810),
    set_pos(5, 5), pos_rect(195, 175, 95, 32));
    g->start.attack = create_slot_attack(g, nb);
    g->start.item = create_inv_empty(g);
}

void create_inv(game_t *g, int nb)
{
    sfTexture *bg = sfTexture_createFromFile("assets/img/UI.png", NULL);
    g->start.empty_bar = sfRectangleShape_create();
    sfRectangleShape_setSize(g->start.empty_bar, set_pos(1916, 46));
    sfRectangleShape_setPosition(g->start.empty_bar, set_pos(2, 2));
    sfRectangleShape_setFillColor(g->start.empty_bar, sfBlack);
    sfRectangleShape_setOutlineThickness(g->start.empty_bar, 2);
    sfRectangleShape_setOutlineColor(g->start.empty_bar,
    sfColor_fromRGB(190, 191, 96));
    g->start.bar_xp = sfRectangleShape_create();
    sfRectangleShape_setPosition(g->start.bar_xp, set_pos(2, 2));
    sfRectangleShape_setSize(g->start.bar_xp, set_pos(0, 0));
    sfRectangleShape_setFillColor(g->start.bar_xp,
    sfColor_fromRGB(34, 102, 221));
    sfIntRect r_bg = pos_rect(195, 270, 50, 50);
    g->start.inv.bg = set_sprite(bg, set_pos(600, 750), set_pos(14, 6));
    sfSprite_setColor(g->start.inv.bg.sprite,
    sfColor_fromRGBA(255, 255, 255, 210));
    sfSprite_setTextureRect(g->start.inv.bg.sprite, r_bg);
    create_slot_empty(g, nb);
}
