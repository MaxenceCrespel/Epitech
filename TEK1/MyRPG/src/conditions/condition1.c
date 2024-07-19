/*
** EPITECH PROJECT, 2022
** condition1
** File description:
** rpg
*/

#include "my.h"

void verrif_new_attack(game_t *g)
{
    for (int i = 0; i < 6; i++) {
        if (g->start.attack[i].status == g->level_up.nb1)
            g->level_up.chose1.have = 1;
        if (g->start.attack[i].status == g->level_up.nb2)
            g->level_up.chose2.have = 1;
    }
}

void change_next_chose(game_t *g)
{
    g->level_up.nb1 = (rand() % 6);
    g->level_up.chose1 = g->chose_attack[g->level_up.nb1];
    sfSprite_setPosition(g->level_up.chose1.img, set_pos(720, 385));
    sfSprite_setPosition(g->level_up.chose1.bg.sprite, set_pos(620, 350));
    sfText_setPosition(g->level_up.chose1.new.text, set_pos(1050, 380));
    sfText_setPosition(g->level_up.chose1.name.text, set_pos(780, 380));
    sfText_setPosition(g->level_up.chose1.descri.text, set_pos(720, 460));
    sfText_setPosition(g->level_up.chose1.descri_new.text, set_pos(720, 460));
    g->level_up.nb2 = (rand() % 6);
    while (g->level_up.nb2 == g->level_up.nb1)
        g->level_up.nb2 = (rand() % 6);
    g->level_up.chose2 = g->chose_attack[g->level_up.nb2];
    sfSprite_setPosition(g->level_up.chose2.img, set_pos(720, 585));
    sfSprite_setPosition(g->level_up.chose2.bg.sprite, set_pos(620, 550));
    sfText_setPosition(g->level_up.chose2.new.text, set_pos(1050, 580));
    sfText_setPosition(g->level_up.chose2.name.text, set_pos(780, 580));
    sfText_setPosition(g->level_up.chose2.descri.text, set_pos(720, 660));
    sfText_setPosition(g->level_up.chose2.descri_new.text, set_pos(720, 660));
    verrif_new_attack(g);
}

void add_one_level(game_t *g)
{
    g->start.xp = 0;
    sfRectangleShape_setSize(g->start.bar_xp, set_pos(0, 0));
    g->start.level++;
    g->achiev[4].actu++;
    char *str = "LV ";
    char *concat = my_strcat(str, my_itoa(g->start.level));
    sfText_setString(g->start.t_lev.text, concat);
    free(concat);
    change_next_chose(g);
}

void delete_attack(add_attack_t **attack, add_attack_t *prev,
add_attack_t **list, game_t *g)
{
    add_attack_t *temp = NULL;
    if (prev == NULL) {
        temp = (*attack)->next;
        sfSprite_destroy((*attack)->sprite.sprite);
        *attack = temp;
        *list = temp;
    } else {
        prev->next = (*attack)->next;
        sfSprite_destroy((*attack)->sprite.sprite);
        *attack = prev->next;
    }
    g->start.nb_attack--;
}

void delete_text(add_text_t **attack, add_text_t *prev, add_text_t **list)
{
    add_text_t *temp = NULL;
    if (prev == NULL) {
        temp = (*attack)->next;
        sfText_destroy((*attack)->damage.text);
        *attack = temp;
        *list = temp;
    } else {
        prev->next = (*attack)->next;
        sfText_destroy((*attack)->damage.text);
        *attack = prev->next;
    }
}
