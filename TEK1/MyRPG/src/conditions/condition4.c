/*
** EPITECH PROJECT, 2022
** condition4.c
** File description:
** rpg
*/

#include "my.h"

void delete_cryst(add_crist_t **attack, add_crist_t *prev, add_crist_t **list)
{
    add_crist_t *temp = NULL;
    if (prev == NULL) {
        temp = (*attack)->next;
        sfSprite_destroy((*attack)->cryst.sprite);
        *attack = temp;
        *list = temp;
    } else {
        prev->next = (*attack)->next;
        sfSprite_destroy((*attack)->cryst.sprite);
        *attack = prev->next;
    }
}

void add_xp(game_t *g, int nb)
{
    g->start.xp += nb;
    int max = (g->start.level * 3) * 60;
    float my_value = (float)g->start.xp / (float)max;
    sfVector2f size = set_pos(1914 * my_value, 46);
    sfRectangleShape_setSize(g->start.bar_xp, size);
}

void recup_cryst(game_t *g, add_crist_t **actuel)
{
    add_crist_t *prev = NULL;
    add_crist_t *attack = *actuel;
    sfFloatRect rect_m;
    sfFloatRect rect = sfSprite_getGlobalBounds(g->start.perso.sprite.sprite);
    rect.height = rect.height + (g->start.perso.magnet * 2);
    rect.top -= g->start.perso.magnet;
    rect.left -= g->start.perso.magnet;
    rect.width += g->start.perso.magnet * 2;
    while (attack) {
        rect_m = sfSprite_getGlobalBounds(attack->cryst.sprite);
        if (sfFloatRect_intersects(&rect, &rect_m, NULL)) {
            add_xp(g, attack->xp);
            delete_cryst(&attack, prev, actuel);
            sfSound_play(g->sound.sound[GEM]);
            g->start.nb_cryst--;
        } else {
            prev = attack;
            attack = attack->next;
        }
    }
}

sfIntRect get_rect_cryst(int nb)
{
    if (nb == 0)
        return pos_rect(706, 36, 9, 12);
    if (nb == 1)
        return pos_rect(710, 48, 9, 12);
    if (nb == 3)
        return pos_rect(736, 36, 9, 12);
    return pos_rect(736, 36, 9, 12);
}

add_crist_t *create_cryst(game_t *g, add_crist_t *llist, add_monster_t *mons)
{
    add_crist_t *element = malloc(sizeof(add_crist_t));
    sfTexture *bg = sfTexture_createFromFile("assets/img/items.png", NULL);
    sfVector2f pos_m = sfSprite_getPosition(mons->sprite.sprite);
    if (mons->type < 3) {
        element->type = 0;
        element->xp = 70;
    } else if (mons->type >= 3 && mons->type < 6) {
        element->type = 1;
        element->xp = 130;
    } else {
        element->type = 2;
        element->xp = 300;
    }
    element->cryst = set_sprite_rect(bg, pos_m, set_pos(3, 3),
    get_rect_cryst(element->type));
    element->next = llist;
    g->start.nb_cryst++;
    return element;
}
