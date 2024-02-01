/*
** EPITECH PROJECT, 2023
** init2
** File description:
** init2
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/my.h"

void init_menu(GLOBAL_T *ALL)
{
    ALL->pic[0].text = sfTexture_createFromFile("image/menu.jpg", NULL);
    ALL->pic[0].sprite = sfSprite_create();
    sfSprite_setTexture(ALL->pic[0].sprite, ALL->pic[0].text, sfTrue);
    ALL->pic[11].text = sfTexture_createFromFile("image/button.png", NULL);
    ALL->pic[11].sprite = sfSprite_create();
    ALL->pic[11].scale.x = 3;
    ALL->pic[11].scale.y = 3;
    ALL->pic[11].pos.x = 510;
    ALL->pic[11].pos.y = 550;
    sfSprite_setScale(ALL->pic[11].sprite, ALL->pic[11].scale);
    sfSprite_setPosition(ALL->pic[11].sprite, ALL->pic[11].pos);
    sfSprite_setTexture(ALL->pic[11].sprite, ALL->pic[11].text, sfTrue);
}

void init_music_button(GLOBAL_T *ALL)
{
    ALL->pic[12].text = sfTexture_createFromFile("image/button.png", NULL);
    ALL->pic[12].sprite = sfSprite_create();
    ALL->pic[12].scale.x = 1.5;
    ALL->pic[12].scale.y = 1.5;
    ALL->pic[12].pos.x = 50;
    ALL->pic[12].pos.y = 790;
    sfSprite_setScale(ALL->pic[12].sprite, ALL->pic[12].scale);
    sfSprite_setPosition(ALL->pic[12].sprite, ALL->pic[12].pos);
    sfSprite_setTexture(ALL->pic[12].sprite, ALL->pic[12].text, sfTrue);
    ALL->pic[13].sprite = sfSprite_create();
    ALL->pic[13].pos.x = 1450;
    ALL->pic[13].pos.y = 790;
    sfSprite_setScale(ALL->pic[13].sprite, ALL->pic[12].scale);
    sfSprite_setPosition(ALL->pic[13].sprite, ALL->pic[13].pos);
    sfSprite_setTexture(ALL->pic[13].sprite, ALL->pic[12].text, sfTrue);
}

void init_replay(GLOBAL_T *ALL)
{
    ALL->pic[4].text = sfTexture_createFromFile("image/menu_fin.jpg", NULL);
    ALL->pic[4].sprite = sfSprite_create();
    sfSprite_setTexture(ALL->pic[4].sprite, ALL->pic[4].text, sfTrue);
    ALL->pic[6].text = sfTexture_createFromFile("image/replay_but.png", NULL);
    ALL->pic[6].sprite = sfSprite_create();
    ALL->pic[6].pos.x = 100;
    ALL->pic[6].pos.y = 300;
    sfSprite_setPosition(ALL->pic[6].sprite, ALL->pic[6].pos);
    sfSprite_setTexture(ALL->pic[6].sprite, ALL->pic[6].text, sfTrue);
    ALL->pic[5].text = sfTexture_createFromFile("image/exit_but.png", NULL);
    ALL->pic[5].sprite = sfSprite_create();
    ALL->pic[5].pos.x = 1300;
    ALL->pic[5].pos.y = 300;
    sfSprite_setPosition(ALL->pic[5].sprite, ALL->pic[5].pos);
    sfSprite_setTexture(ALL->pic[5].sprite, ALL->pic[5].text, sfTrue);
}

void init_ninja(GLOBAL_T *ALL)
{
    ALL->pic[10].text = sfTexture_createFromFile("image/ninattack2.png", NULL);
    ALL->pic[10].sprite = sfSprite_create();
    ALL->pic[10].scale.x = 1.2;
    ALL->pic[10].scale.y = 1.2;
    sfSprite_setScale(ALL->pic[10].sprite, ALL->pic[10].scale);
    sfSprite_setTexture(ALL->pic[10].sprite, ALL->pic[10].text, sfTrue);
    ALL->pic[14].text = sfTexture_createFromFile("image/ninattack1.png", NULL);
    ALL->pic[14].sprite = sfSprite_create();
    sfSprite_setScale(ALL->pic[14].sprite, ALL->pic[10].scale);
    sfSprite_setTexture(ALL->pic[14].sprite, ALL->pic[14].text, sfTrue);
    ALL->pic[15].text = sfTexture_createFromFile("image/ninjadie.png", NULL);
    ALL->pic[15].sprite = sfSprite_create();
    sfSprite_setScale(ALL->pic[15].sprite, ALL->pic[10].scale);
    sfSprite_setTexture(ALL->pic[15].sprite, ALL->pic[15].text, sfTrue);
    ALL->pic[16].text = sfTexture_createFromFile("image/ninjarun.png", NULL);
    ALL->pic[16].sprite = sfSprite_create();
    sfSprite_setScale(ALL->pic[16].sprite, ALL->pic[10].scale);
    sfSprite_setTexture(ALL->pic[16].sprite, ALL->pic[16].text, sfTrue);
}
