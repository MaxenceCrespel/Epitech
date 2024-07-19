/*
** EPITECH PROJECT, 2022
** init_spell3.c
** File description:
** Init spell.
*/

#include "my.h"

chose_attack_t create_chose_fire(game_t *g)
{
    chose_attack_t attack;
    sfTexture *bg = sfTexture_createFromFile("assets/img/UI.png", NULL);
    sfTexture *img = sfTexture_createFromFile("assets/img/items.png", NULL);
    attack.bg = set_sprite_rect(bg, set_pos(620, 350), set_pos(12, 4),
    pos_rect(195, 270, 50, 50));
    attack.descri = init_text("assets/fonts/ANY.ttf", 25,
    set_pos(720, 460), langage[g->option.langage][6][0]);
    attack.descri_new = init_text("assets/fonts/ANY.ttf",
    25, set_pos(720, 460), langage[g->option.langage][6][1]);
    attack.have = 0;
    attack.name = init_text("assets/fonts/ANY.ttf",
    25, set_pos(780, 380), langage[g->option.langage][6][2]);
    attack.new = init_text("assets/fonts/ANY.ttf",
    25, set_pos(1050, 380), langage[g->option.langage][6][3]);
    sfText_setColor(attack.new.text, sfYellow);
    attack.img = sfSprite_copy(g->stat_attack[1].img.sprite);
    sfSprite_setPosition(attack.img, set_pos(720, 385));
    return attack;
}

chose_attack_t create_chose_couteau(game_t *g)
{
    chose_attack_t attack;
    sfTexture *bg = sfTexture_createFromFile("assets/img/UI.png", NULL);
    sfTexture *img = sfTexture_createFromFile("assets/img/items.png", NULL);
    attack.bg = set_sprite_rect(bg, set_pos(620, 350),
    set_pos(12, 4), pos_rect(195, 270, 50, 50));
    attack.descri = init_text("assets/fonts/ANY.ttf",
    25, set_pos(720, 460), langage[g->option.langage][7][0]);
    attack.descri_new = init_text("assets/fonts/ANY.ttf",
    25, set_pos(720, 460), langage[g->option.langage][7][1]);
    attack.have = 0;
    attack.name = init_text("assets/fonts/ANY.ttf",
    25, set_pos(780, 380), langage[g->option.langage][7][2]);
    attack.new = init_text("assets/fonts/ANY.ttf",
    25, set_pos(1050, 380), langage[g->option.langage][7][3]);
    sfText_setColor(attack.new.text, sfYellow);
    attack.img = sfSprite_copy(g->stat_attack[2].img.sprite);
    sfSprite_setPosition(attack.img, set_pos(720, 385));
    return attack;
}

chose_attack_t create_chose_lorel(game_t *g)
{
    chose_attack_t attack;
    sfTexture *bg = sfTexture_createFromFile("assets/img/UI.png", NULL);
    sfTexture *img = sfTexture_createFromFile("assets/img/items.png", NULL);
    attack.bg = set_sprite_rect(bg, set_pos(620, 350),
    set_pos(12, 4), pos_rect(195, 270, 50, 50));
    attack.descri = init_text("assets/fonts/ANY.ttf",
    25, set_pos(720, 460), langage[g->option.langage][8][0]);
    attack.descri_new = init_text("assets/fonts/ANY.ttf",
    25, set_pos(720, 460), langage[g->option.langage][8][1]);
    attack.have = 0;
    attack.name = init_text("assets/fonts/ANY.ttf",
    25, set_pos(780, 380), langage[g->option.langage][8][2]);
    attack.new = init_text("assets/fonts/ANY.ttf",
    25, set_pos(1050, 380), langage[g->option.langage][8][3]);
    sfText_setColor(attack.new.text, sfYellow);
    attack.img = sfSprite_copy(g->stat_attack[3].img.sprite);
    sfSprite_setPosition(attack.img, set_pos(720, 385));
    return attack;
}

chose_attack_t create_chose_ms(game_t *g)
{
    chose_attack_t attack;
    sfTexture *bg = sfTexture_createFromFile("assets/img/UI.png", NULL);
    sfTexture *img = sfTexture_createFromFile("assets/img/items.png", NULL);
    attack.bg = set_sprite_rect(bg, set_pos(620, 350),
    set_pos(12, 4), pos_rect(195, 270, 50, 50));
    attack.descri = init_text("assets/fonts/ANY.ttf", 25,
    set_pos(720, 460), langage[g->option.langage][9][0]);
    attack.descri_new = init_text("assets/fonts/ANY.ttf",
    25, set_pos(720, 460), langage[g->option.langage][9][1]);
    attack.have = 0;
    attack.name = init_text("assets/fonts/ANY.ttf",
    25, set_pos(780, 380), langage[g->option.langage][9][2]);
    attack.new = init_text("assets/fonts/ANY.ttf",
    25, set_pos(1050, 380), langage[g->option.langage][9][3]);
    sfText_setColor(attack.new.text, sfYellow);
    attack.img = sfSprite_copy(g->stat_attack[4].img.sprite);
    sfSprite_setPosition(attack.img, set_pos(720, 385));
    return attack;
}

chose_attack_t create_chose_cooldown(game_t *g)
{
    chose_attack_t attack;
    sfTexture *bg = sfTexture_createFromFile("assets/img/UI.png", NULL);
    sfTexture *img = sfTexture_createFromFile("assets/img/items.png", NULL);
    attack.bg = set_sprite_rect(bg, set_pos(620, 350),
    set_pos(12, 4), pos_rect(195, 270, 50, 50));
    attack.descri_new = init_text("assets/fonts/ANY.ttf",
    25, set_pos(720, 460), langage[g->option.langage][10][0]);
    attack.descri = init_text("assets/fonts/ANY.ttf",
    25, set_pos(720, 460), langage[g->option.langage][10][1]);
    attack.have = 0;
    attack.name = init_text("assets/fonts/ANY.ttf",
    25, set_pos(780, 380), langage[g->option.langage][10][2]);
    attack.new = init_text("assets/fonts/ANY.ttf",
    25, set_pos(1050, 380), langage[g->option.langage][10][3]);
    sfText_setColor(attack.new.text, sfYellow);
    attack.img = sfSprite_copy(g->stat_attack[5].img.sprite);
    sfSprite_setPosition(attack.img, set_pos(720, 385));
    return attack;
}
