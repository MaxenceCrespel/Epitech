/*
** EPITECH PROJECT, 2022
** condition6
** File description:
** rpg
*/

#include "my.h"

void verrif_have_attack2(game_t *g, int cmp, int nb, int i)
{
    if (cmp > g->stat_attack[nb].cooldown -
        ((g->stat_attack[nb].cooldown / 100) * g->start.perso.cooldown))
            g->start.attack[i].have = 1;
        else
            g->start.attack[i].have = 0;
}

void verrif_have_attack(game_t *g)
{
    int nb;
    sfTime time;
    sfColor base;
    sfSprite *copy_img;
    int cmp;
    time = sfClock_getElapsedTime(g->start.attack[0].clock);
    for (int i = 0; i < 6; i++) {
        nb = g->start.attack[i].status;
        if (!g->start.attack[i].att.img.sprite || nb == 4 || nb == 5)
            continue;
        time = sfClock_getElapsedTime(g->start.attack[i].clock);
        cmp = sfTime_asMilliseconds(time);
        if ((cmp > g->stat_attack[nb].cooldown -
        ((g->stat_attack[nb].cooldown / 100) * g->start.perso.cooldown))
        && nb == 3 && (g->start.lorel != g->start.lorel_max)) {
            g->start.lorel++;
            sfClock_restart(g->start.attack[i].clock);
        }
        verrif_have_attack2(g, cmp, nb, i);
    }
}

void quit_game(game_t *g)
{
    g->scene = 0;
    sfMusic_stop(g->music.music[2]);
    sfMusic_stop(g->music.music[1]);
    sfMusic_play(g->music.music[0]);
    g->achiev[0].actu = g->achiev[0].actu + g->start.monster_kill;
    g->save.i_or = g->save.i_or + g->start.or_win;
    g->achiev[1].actu += g->start.or_win;
    for (int i = 0; g->achiev[i].img_opt.sprite; i++)
        sfText_setString(g->achiev[i].t_actu.text,
        my_itoa(g->achiev[i].actu));
    sfText_setString(g->save.t_or.text, my_itoa(g->save.i_or));
    g->writer.x = 0;
    g->writer.status = 0;
}

void verrif_lose(game_t *g)
{
    if (g->start.perso.life <= 0) {
        sfSound_play(g->sound.sound[LOSE]);
        g->scene = 9;
    }
}

sfVector2f get_pos_monster(void)
{
    sfVector2f pos;
    pos.x = rand() % 2000;
    if (pos.x <= 1000)
        pos.x = pos.x * (-1);
    if (pos.x > 1000)
        pos.x += 1000;
    pos.y = rand() % 1000;
    if (pos.y <= 500)
        pos.y = pos.y * (-1);
    if (pos.y > 500)
        pos.y += 500;
    return pos;
}
