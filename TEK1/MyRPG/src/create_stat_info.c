/*
** EPITECH PROJECT, 2022
** create_stat_info
** File description:
** rpg
*/

#include "my.h"

text_t *create_stat_name(void)
{
    char *font = "assets/fonts/ANY.ttf";
    text_t *stat = malloc(sizeof(text_t) * 12);
    stat[11].text = NULL;
    stat[0] = init_text(font, 20, set_pos(160, 405), "Max Health");
    stat[1] = init_text(font, 20, set_pos(160, 430), "Recovery");
    stat[2] = init_text(font, 20, set_pos(160, 455), "MoveSpeed");
    stat[3] = init_text(font, 20, set_pos(160, 480), "Armor");
    stat[4] = init_text(font, 20, set_pos(160, 530), "Area");
    stat[5] = init_text(font, 20, set_pos(160, 555), "Speed");
    stat[6] = init_text(font, 20, set_pos(160, 580), "CoolDown");
    stat[7] = init_text(font, 20, set_pos(160, 605), "Penetration");
    stat[8] = init_text(font, 20, set_pos(160, 655), "Duration");
    stat[9] = init_text(font, 20, set_pos(160, 680), "Magnet");
    stat[10] = init_text(font, 20, set_pos(160, 705), "Growth");
    return stat;
}

text_t *create_info_perso(stat_cara_t pr, game_t *g)
{
    add_stat_save(g, &pr);
    char *font = "assets/fonts/ANY.ttf";
    text_t *stat = malloc(sizeof(text_t) * 12);
    stat[11].text = NULL;
    stat[0] = init_text(font, 20, set_pos(321, 405), my_itoa(pr.max_life));
    stat[1] = init_text(font, 20, set_pos(321, 430), my_itoa(pr.recov));
    stat[2] = init_text(font, 20, set_pos(321, 455), my_itoa(pr.ms));
    stat[3] = init_text(font, 20, set_pos(321, 480), my_itoa(pr.armor));
    stat[4] = init_text(font, 20, set_pos(321, 530), my_itoa(pr.area));
    stat[5] = init_text(font, 20, set_pos(321, 555), my_itoa(pr.speed));
    stat[6] = init_text(font, 20, set_pos(321, 580), my_itoa(pr.cooldown));
    stat[7] = init_text(font, 20, set_pos(321, 605), my_itoa(pr.pene));
    stat[8] = init_text(font, 20, set_pos(321, 655), my_itoa(pr.duration));
    stat[9] = init_text(font, 20, set_pos(321, 680), my_itoa(pr.magnet));
    stat[10] = init_text(font, 20, set_pos(321, 705), my_itoa(pr.growth));
    return stat;
}
