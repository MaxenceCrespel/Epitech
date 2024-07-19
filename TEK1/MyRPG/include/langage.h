/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-mahe.fauvart
** File description:
** langage
*/

#ifndef LANGAGE_H_
    #define LANGAGE_H_

    static char *NAME_IMG_FR[] = {"Sante max", "Recuperation", "  Vitesse",
    "   Armure",
    "   Zone", "  Vitesse", " CoolDown", "Penetration", "   Duree",
    " Aimant", "Croissance"};
    static char *NAME_PERSO_FR[] = {"Antonio", "Axel", "Mahe", "Maxence",
    "Crap", "Poe"};
    static char *NAME_SAVE_FR[] = {"or", "Sante Maximale", "Recuperation",
    "Vitesse de deplacement",
    "Armure", "Zone", "Vitesse", "CoolDown", "Penetration",
    "Duration", "Aimant", "Croissance"};
    static char *NAME_POWER_FR[] = {
    "Augmente la sante \nmaximale de 10%\npar rang",
    "Recupere 1 HP\npar rang par seconde",
    "Le personnage se deplace\n5% plus rapidement par\nrang",
    "Reduit les degats pris\nde 1 par rang",
    "Augmente la zone de \ndegats de 5% par rang",
    "Les projectiles se \ndeplace 10% plus \nrapidement par rang",
    "Reduit le cooldown \nde 3% par rang",
    "Les sorts touchent\n1 monstres de plus\npar rang",
    "Les effets des sorts\ndurent 15% de plus\npar rang",
    "La zone de recuperation\ndes objets augmente\nde 25% par rang",
    "Gagne 3% d'experiences\nen plus par rang"};
    static char *NAME_ACHIEV_FR[] = {"Tuez 100 Monstres",
    "Recuperez 2500 pieces d'or",
    "Courez sur 20000 metres", "Recuperez 20 objets",
    "Montez jusqu'au niveau 50", "Montez jusqu'au niveau 50",
    "Montez jusqu'au niveau 50",
    "Montez jusqu'au niveau 50", "Montez jusqu'au niveau 50",
    "Montez jusqu'au niveau 50"};
    static char *TALK_FR[] = {"Bonjour jeune aventurier."
    "\nSi tu es ici c'est parce que j'ai besoin de toi.\nJ'ai perdu 6 objets "
    "et tu dois m'aider a les retrouver.", "Mais fais attention, durant ta "
    "recherche, des monstres de plus en plus\nforts vont venir t'attaquer.",
    "Je t'attendrai ici j'espere que tu reussiras.\n"
    "Que la force soit avec toi.",
    "Il te reste encore 6 objets a trouver.",
    "Il te reste encore 5 objets a trouver.",
    "Il te reste encore 4 objets a trouver.",
    "Il te reste encore 3 objets a trouver.",
    "Il te reste encore 2 objets a trouver.",
    "Il te reste encore 1 objet a trouver.",
    "Merci, tu as recupere mes objets egares, maintenant il te reste une "
    "etape.\nEliminer les deux gardiens du temps.", "Bien joue, tu as "
    "reussi ma quete, Pour te feliciter je te donne 500 pieces d'or\n"
    "maintenant que veux-tu faire ?\n\nContinuer d'xp.\n\nRetourner au lobby.",
    "Merci encore pour ton aide, fais attention les monstres rodent toujours "
    "autour.\n\n\nContinuer d'xp.\n\nRetourner au lobby."};
    static char *FIRE_FR[] = {"Augmente les degats de\nla boule",
    "Lance des boules de feu", "Boule de feu", "Nouveau!"};
    static char *KNIFE_FR[] = {"Augmente les degats\ndes couteaux",
    "Lance des couteaux", "Couteau", "Nouveau!"};
    static char *SHIELD_FR[] = {"Augmente le nombre d'attaque\na absorber",
    "Bouclier qui absorbe\ndes attaques", "Bouclier", "Nouveau!"};
    static char *BOOTS_FR[] = {"Augmente la vitesse",
    "Bottes qui augmentent\nvotre vitesse", "bottes", "Nouveau!"};
    static char *CD_FR[] = {"Reduit le cooldown de\nvos competences",
    "Reduit de 3% supplementaire\nle cooldown", "Cooldown", "Nouveau!"};
    static char *LASH_FR[] = {"Augmente les degats du fouet",
    "Lance un coup de fouet", "Fouet", "Nouveau!"};
    static char **french[] = {NAME_IMG_FR, NAME_PERSO_FR, NAME_SAVE_FR,
    NAME_POWER_FR, NAME_ACHIEV_FR, TALK_FR, FIRE_FR, KNIFE_FR, SHIELD_FR,
    BOOTS_FR, CD_FR, LASH_FR};

    static char *NAME_IMG_ENG[] = {"Max Health", " Recovery", " MoveSpeed",
    "   Armor", "   Area", "   Speed", " CoolDown", "Penetration", " Duration",
    "  Magnet", "  Growth"};
    static char *NAME_PERSO_ENG[] = {"Antonio", "Axel", "Mahe",
    "Maxence", "Crap", "Poe"};
    static char *NAME_SAVE_ENG[] = {"or", "Max_Health", "Recovery",
    "MoveSpeed", "Armor", "Area", "Speed", "CoolDown", "Penetration",
    "Duration", "Magnet", "Growth"};
    static char *NAME_POWER_ENG[] = {"Augments max health by\n10% per rank",
    "Recovers 1 HP\nper rank per seconds",
    "Character moves 5%\nfaster per rank",
    "reduces incoming damage\nby 1 per rank",
    "Augments area of attacks\nby 5% per rank",
    "Projectiles moves 10%\nfaster per rank", "Reduces cooldown 3%\nper rank",
    "Spell touch +1 monster\nper rank",
    "Effects from spells last\n15% longer per rank",
    "Items pickup range +25%\nper rank", "Gains 3% more experience\nper rank"};
    static char *NAME_ACHIEV_ENG[] = {"Kill 100 Monsters", "Get 2500 golds",
    "Run 20000 meters", "Recup a total of 20 objects",
    "Level up a total of 50 level", "Level up a total of 50 level",
    "Level up a total of 50 level",
    "Level up a total of 50 level", "Level up a total of 50 level",
    "Level up a total of 50 level"};
    static char *TALK_ENG[] = {"Hello young adventurer.\nIf you are here it is"
    " because I need you.\nI lost 6 items and you must help me to find them.",
    "But be careful, during your search, stronger and stronger monsters\nwill "
    "come and attack you.",
    "I will wait here for you, I hope you will succeed.\nMay the force be with"
    " you.",
    "You still have 6 items to find.", "You still have 5 items to find.",
    "You still have 4 items to find.", "You still have 3 items to find.",
    "You still have 2 items to find.", "You still have 1 item to find.",
    "Thank you, you got back my items, now you have one step "
    "left.\nEliminate the two time guardians.",
    "Play it right, you did it right, and I will give you 500 coins "
    "of gold\nNow what do you want to do?\n\nContinue from xp.\n\nReturn "
    "to the lobby.",
    "Thanks again for your help, be careful the monsters are still lurking "
    "around.\n\n\nContinue from xp.\n\nReturn to the lobby."};
    static char *FIRE_ENG[] = {"increases fireball damage", "Throw fireballs",
    "Fireball", "New!"};
    static char *KNIFE_ENG[] = {"Increases knife damage", "Throw knifes",
    "Knife", "New!"};
    static char *SHIELD_ENG[] = {"Increases the number of\nattacks to absorb",
    "Shield that absorbs\nattacks", "Shield", "New!"};
    static char *BOOTS_ENG[] = {"Increase the speed",
    "Boots that increase\nyour speed", "boots", "New!"};
    static char *CD_ENG[] = {"Reduces the cooldown\nof your skills",
    "Reduces the cooldown by an\nadditional 3%", "Cooldown", "New!"};
    static char *LASH_ENG[] = {"Increase lash damage",
    "Gives a whiplash", "Lash", "New!"};
    static char **english[] = {NAME_IMG_ENG, NAME_PERSO_ENG, NAME_SAVE_ENG,
    NAME_POWER_ENG, NAME_ACHIEV_ENG, TALK_ENG, FIRE_ENG, KNIFE_ENG, SHIELD_ENG,
    BOOTS_ENG, CD_ENG, LASH_ENG};
    static char ***langage[] = {french, english};
#endif
