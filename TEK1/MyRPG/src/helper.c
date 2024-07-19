/*
** EPITECH PROJECT, 2022
** helper.c
** File description:
** Display the helper of the game.
*/

#include "my.h"

void helper2(void)
{
    my_printf("You have the possibility to use different spells\n");
    my_printf("and attacks:\n\n");
    my_printf("- The whip\n");
    my_printf("- The fireball\n");
    my_printf("- Throw knives\n");
    my_printf("\nI will wait here for you, I hope you will succeed.\n");
    my_printf("\n-------------------------------------------------------\n");
    my_printf("|               How to launch the game                |");
    my_printf("\n-------------------------------------------------------\n");
    my_printf("    ./my_rpg \n");
}

void helper3(void)
{
    my_printf(" - SPACE = default Spell/attack\n\n");
    my_printf(" - 1 = first Spell/attack\n\n");
    my_printf(" - 2 = Second Spell/attack\n\n");
    my_printf(" - Z & Directional arrow up = Move forward\n\n");
    my_printf(" - S & Directional arrow down = Move backwards\n\n");
    my_printf(" - Q & Directional arrow left = Move left\n\n");
    my_printf(" - D & Directional arrow right = Move right\n\n");
}

void helper(void)
{
    my_printf("\n-------------------------------------------------------\n");
    my_printf("|               Vampire Survivor HELPER               |");
    my_printf("\n-------------------------------------------------------\n");
    my_printf("Dear young adventurer,\n\n");
    my_printf("If you are here it's because I need you.\n");
    my_printf("I lost 6 items and you must help me to find them.");
    my_printf("\n\nBut be careful, during your search, stronger \n");
    my_printf("and stronger monsters will come and attack you\n\n");
    helper2();
    my_printf("\n-------------------------------------------------------\n");
    my_printf("|                Vampire Survivor Bind                |");
    my_printf("\n-------------------------------------------------------\n");
    my_printf(" - ESC = QUIT/Open menu/\n\n");
    helper3();
    my_printf(" \n\n");
}

int display_help(void)
{
    helper();
    return 0;
}
