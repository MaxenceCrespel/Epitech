/*
** EPITECH PROJECT, 2022
** condition
** File description:
** rpg
*/

#include "my.h"

void remove_monster_bis(game_t *g, add_monster_t **actuel,
add_monster_t *attack, add_monster_t *prev)
{
    g->start.d_crys = create_cryst(g, g->start.d_crys, attack);
    g->start.nb_monster--;
    g->start.monster_kill += 1;
    sfText_setString(g->start.t_mons_kill.text,
    my_itoa(g->start.monster_kill));
    sfText_setPosition(g->start.t_mons_kill.text,
    set_pos(1430 - (my_strlen(my_itoa(g->start.monster_kill)) * 22),
    70));
    g->start.or_win += 5;
    if (g->start.end != 0) {
        g->start.or_win += 25;
        g->start.end++;
    }
    sfText_setString(g->start.t_or.text, my_itoa(g->start.or_win));
    sfText_setPosition(g->start.t_or.text,
    set_pos(1630 - (my_strlen(my_itoa(g->start.or_win)) * 22), 70));
}

void remove_monster(game_t *g, add_monster_t **actuel)
{
    add_monster_t *prev = NULL;
    add_monster_t *attack = *actuel;

    while (attack) {
        if (attack->life <= 0) {
            remove_monster_bis(g, actuel, attack, prev);
            delete_monster(&attack, prev, actuel);
        } else {
            prev = attack;
            attack = attack->next;
        }
    }
}

void move_monster(game_t *g)
{
    add_monster_t *tmp = g->start.d_monster;
    sfTime time = sfClock_getElapsedTime(tmp->time);
    int rotate;
    while (tmp) {
        time = sfClock_getElapsedTime(tmp->time);
        if (sfTime_asMilliseconds(time) >= 180) {
            sfSprite_setTextureRect(tmp->sprite.sprite,
            tmp->rect[tmp->nb_rect++]);
            tmp->nb_rect == 4 ? tmp->nb_rect = 0 : 0;
            rotate = get_rotate(tmp->nb_rect);
            sfSprite_setRotation(tmp->sprite.sprite, rotate);
            sfClock_restart(tmp->time);
        }
        monster_move(g, tmp);
        tmp = tmp->next;
    }
}

void move_attack(game_t *g)
{
    add_attack_t *temp = g->start.d_attack;

    while (temp) {
        if (temp->status != 0)
            sfSprite_move(temp->sprite.sprite, temp->dir);
        temp = temp->next;
    }
}

void conditions_scene(game_t *g)
{
    set_volume(g);
    ft_volume(g);
    if (g->scene == 1)
        data_game(g);
    if (g->scene == 2)
        data_menu(g);
}
