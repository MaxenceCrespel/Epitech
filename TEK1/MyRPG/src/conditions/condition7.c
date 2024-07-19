/*
** EPITECH PROJECT, 2022
** condition7
** File description:
** rpg
*/

#include "my.h"

int mirror_perso(game_t *g)
{
    int x = 0;

    if (g->start.r_l == 0) {
        sfSprite_setPosition(g->start.perso.sprite.sprite, set_pos(900, 500));
        sfSprite_setScale(g->start.perso.sprite.sprite, set_pos(3, 3));
    }
    if (g->start.r_l == 1) {
        x = g->start.perso.rect[0].width * 3;
        sfSprite_setPosition(g->start.perso.sprite.sprite,
        set_pos(900 + x, 500));
        sfSprite_setScale(g->start.perso.sprite.sprite, set_pos(-3, 3));
    }
    return (0);
}

void data_game(game_t *g)
{
    if (g->start.xp >= (g->start.level * 3) * 60) {
        add_one_level(g);
        sfSound_play(g->sound.sound[LEVEL_UP]);
        g->scene = 4;
    }
    if (g->start.nb_attack > 0) {
        move_attack(g);
        verrif_delete_attack(g, &(g->start.d_attack));
    }
    mirror_perso(g);
    regen_life(g);
    event_move(g);
    verrif_have_attack(g);
    verrif_lose(g);
    data_game2(g);
    change_rect_reaper(g);
    verif_recup_item(g);
    if (g->start.nb_item != 6)
        see_dir_ob(g);
}

void data_menu(game_t *g)
{
    static int i = 0;
    static int tmp = 0;
    if (g->menu.select != tmp)
        i = 0;
    if (g->menu.select != -1 && i == 0) {
        g->d_stat.t_stat = create_info_perso(g->stat_p[g->menu.select], g);
        i++;
    }
    tmp = g->menu.select;
}
