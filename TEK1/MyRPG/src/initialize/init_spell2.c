/*
** EPITECH PROJECT, 2022
** init_spell2.c
** File description:
** Init spell.
*/

#include "my.h"

stat_attack_t create_attack_ms(void)
{
    stat_attack_t attack;
    sfTexture *bg = sfTexture_createFromFile("assets/img/items.png", NULL);
    attack.actif = 1;
    attack.img = set_sprite_rect(bg, set_pos(150, 150),
    set_pos(3, 3), pos_rect(382, 39, 16, 17));
    return attack;
}

stat_attack_t create_attack_cooldown(void)
{
    stat_attack_t attack;
    sfTexture *bg = sfTexture_createFromFile("assets/img/items.png", NULL);
    attack.actif = 1;
    attack.img = set_sprite_rect(bg, set_pos(150, 150),
    set_pos(3, 3), pos_rect(532, 1, 15, 14));
    return attack;
}

stat_attack_t *create_attack_stat(void)
{
    stat_attack_t *attack = malloc(sizeof(stat_attack_t) * 7);
    attack[6].img.sprite = NULL;
    attack[0] = create_attack_fouet();
    attack[1] = create_attack_fire();
    attack[2] = create_attack_couteau();
    attack[3] = create_attack_lorel();
    attack[4] = create_attack_ms();
    attack[5] = create_attack_cooldown();
    return attack;
}

void create_scene_up(game_t *g)
{
    char *str = "\t   Appuyer sur tab"
    "\n   pour ouvrir l'inventaire\net voir vos attaques actuelles";
    sfTexture *bg = sfTexture_createFromFile("assets/img/UI.png", NULL);
    g->level_up.bg = set_sprite_rect(bg, set_pos(550, 150),
    set_pos(16, 18), pos_rect(228, 175, 48, 48));
    g->level_up.level_up = init_text("assets/fonts/ANY.ttf", 50,
    set_pos(790, 245), "LEVEL UP!");
    g->level_up.info = init_text("assets/fonts/ANY.ttf", 25,
    set_pos(720, 770), str);
}

chose_attack_t create_chose_fouet(game_t *g)
{
    chose_attack_t attack;
    sfTexture *bg = sfTexture_createFromFile("assets/img/UI.png", NULL);
    sfTexture *img = sfTexture_createFromFile("assets/img/items.png", NULL);
    attack.bg = set_sprite_rect(bg, set_pos(620, 350),
    set_pos(12, 4), pos_rect(195, 270, 50, 50));
    attack.descri = init_text("assets/fonts/ANY.ttf", 25,
    set_pos(720, 460), langage[g->option.langage][11][0]);
    attack.descri_new = init_text("assets/fonts/ANY.ttf",
    25, set_pos(720, 460), langage[g->option.langage][11][1]);
    attack.have = 0;
    attack.name = init_text("assets/fonts/ANY.ttf",
    25, set_pos(780, 380), langage[g->option.langage][11][2]);
    attack.new = init_text("assets/fonts/ANY.ttf", 25,
    set_pos(1050, 380), langage[g->option.langage][11][3]);
    sfText_setColor(attack.new.text, sfYellow);
    attack.img = sfSprite_copy(g->stat_attack[0].img.sprite);
    sfSprite_setPosition(attack.img, set_pos(720, 385));
    return attack;
}
