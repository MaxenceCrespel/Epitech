/*
** EPITECH PROJECT, 2022
** condition 9
** File description:
**  add fuction
*/

#include "my.h"

void data_game2(game_t *g)
{
    if (g->start.nb_text >= 1)
        remove_text(g, &(g->start.d_text));
    if (g->start.end == 0)
        spawn_monster(g);
    if (g->start.nb_cryst >= 1)
        recup_cryst(g, &(g->start.d_crys));
    if (g->start.nb_monster >= 1)
        remove_monster(g, &(g->start.d_monster));
    if (g->start.nb_monster >= 1) {
        move_monster(g);
        mirror_monster(g);
    }
}

void add_slot_item(game_t *g, int nb)
{
    for (int i = 0; i < 6; i++) {
        if (g->start.item[i].have == 0) {
            g->start.item[i].img.sprite =
            sfSprite_copy(g->item_l[nb].img.sprite);
            sfSprite_setPosition(g->start.item[i].img.sprite,
            set_pos(735 + (i * 80), 905));
            g->start.item[i].have = 1;
            g->start.nb_item++;
            g->achiev[3].actu++;
            break;
        }
    }
}

void verif_recup_item(game_t *g)
{
    sfFloatRect img = sfSprite_getGlobalBounds(g->start.perso.sprite.sprite);
    sfFloatRect item;
    for (int i = 0; i < 6; i++) {
        if (g->item_l[i].status == 0)
            continue;
        item = sfSprite_getGlobalBounds(g->item_l[i].img.sprite);
        if (sfFloatRect_intersects(&img, &item, NULL)) {
            g->item_l[i].status = 0;
            add_slot_item(g, i);
        }
    }
}

int set_pos_arrow_obj(game_t *g, sfVector2f pos)
{
    if (pos.x >= 1920) {
        sfSprite_setRotation(g->arrow.sprite, 0);
        sfSprite_setPosition(g->arrow.sprite, set_pos(1850, 519));
    }
    if (pos.x < 0) {
        sfSprite_setRotation(g->arrow.sprite, 180);
        sfSprite_setPosition(g->arrow.sprite, set_pos(90, 519));
    }
    if (pos.y >= 1080) {
        sfSprite_setRotation(g->arrow.sprite, 90);
        sfSprite_setPosition(g->arrow.sprite, set_pos(939, 950));
    }
    if (pos.y < 0) {
        sfSprite_setPosition(g->arrow.sprite, set_pos(939, 90));
        sfSprite_setRotation(g->arrow.sprite, 270);
    }
    if (pos.x >= 0 && pos.x < 1919 && pos.y >= 0 && pos.y < 1079) {
        sfSprite_setPosition(g->arrow.sprite, set_pos(-1000, 0));
    }
    return 1;
}

void see_dir_ob(game_t *g)
{
    sfVector2f pos;
    for (int i = 0; i < 6; i++) {
        if (g->item_l[i].status != 1)
            continue;
        pos = sfSprite_getPosition(g->item_l[i].img.sprite);
        set_pos_arrow_obj(g, pos);
    }
}
