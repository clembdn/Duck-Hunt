/*
** EPITECH PROJECT, 2023
** init
** File description:
** init
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/my.h"

int random_nbr(int min, int max)
{
    int random = rand() % (max - min + 1) + min;

    srand(time(NULL));
    return (random);
}

void init_window(GLOBAL_T *ALL)
{
    ALL->settings.mode.width = 1920;
    ALL->settings.mode.height = 1080;
    ALL->settings.mode.bitsPerPixel = 64;
    ALL->settings.win = sfRenderWindow_create(ALL->settings.mode,
        "Ninja Hunt", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(ALL->settings.win, 60);
    ALL->music.theme = sfMusic_createFromFile("image/theme.ogg");
    ALL->music.shuriken = sfMusic_createFromFile("image/shuriken.ogg");
    ALL->music.dead = sfMusic_createFromFile("image/dead.ogg");
    ALL->music.dead2 = sfMusic_createFromFile("image/dead.ogg");
    ALL->music.dead3 = sfMusic_createFromFile("image/dead.ogg");
    ALL->game.currentF = 0;
    ALL->game.currentF2 = 0;
    ALL->game.currentF3 = 0;
    ALL->game.FTime = 0.2f;
    ALL->game.FTime2 = 0.2f;
    ALL->game.FTime3 = 0.2f;
    ALL->game.f = 0.0f;
    ALL->game.f2 = 0.0f;
    ALL->game.f3 = 0.0f;
}

void init_background(GLOBAL_T *ALL)
{
    ALL->pic[1].text = sfTexture_createFromFile("image/background.jpg", NULL);
    ALL->pic[1].sprite = sfSprite_create();
    sfSprite_setTexture(ALL->pic[1].sprite, ALL->pic[1].text, sfTrue);
    ALL->pic[8].text = sfTexture_createFromFile("image/menu_playon.jpg", NULL);
    ALL->pic[8].sprite = sfSprite_create();
    sfSprite_setTexture(ALL->pic[8].sprite, ALL->pic[8].text, sfTrue);
    ALL->pic[9].text = sfTexture_createFromFile("image/menu_son.jpg", NULL);
    ALL->pic[9].sprite = sfSprite_create();
    sfSprite_setTexture(ALL->pic[9].sprite, ALL->pic[9].text, sfTrue);
    ALL->pic[7].text = sfTexture_createFromFile("image/menu_soff.jpg", NULL);
    ALL->pic[7].sprite = sfSprite_create();
    sfSprite_setTexture(ALL->pic[7].sprite, ALL->pic[7].text, sfTrue);
}

void init_cursor(GLOBAL_T *ALL)
{
    ALL->pic[2].text = sfTexture_createFromFile("image/cursor.png", NULL);
    ALL->pic[2].sprite = sfSprite_create();
    ALL->pic[2].scale = (sfVector2f){0.5, 0.5};
    sfSprite_setScale(ALL->pic[2].sprite, ALL->pic[2].scale);
    sfSprite_setTexture(ALL->pic[2].sprite, ALL->pic[2].text, sfTrue);
    ALL->pic[3].text = sfTexture_createFromFile("image/arm.png", NULL);
    ALL->pic[3].sprite = sfSprite_create();
    ALL->pic[3].scale = (sfVector2f){1.2, 1.2};
    sfSprite_setScale(ALL->pic[3].sprite, ALL->pic[3].scale);
    sfSprite_setTexture(ALL->pic[3].sprite, ALL->pic[3].text, sfTrue);
    ALL->score.font = sfFont_createFromFile("image/stocky.ttf");
    ALL->score.scoretxt = sfText_create();
    sfText_setFont(ALL->score.scoretxt, ALL->score.font);
    sfText_setCharacterSize(ALL->score.scoretxt, 30);
    sfText_setPosition(ALL->score.scoretxt, (sfVector2f){50.0f, 50.0f});
    ALL->score.nbrtxt = sfText_create();
    sfText_setFont(ALL->score.nbrtxt, ALL->score.font);
    sfText_setCharacterSize(ALL->score.nbrtxt, 30);
    sfText_setPosition(ALL->score.nbrtxt, (sfVector2f){100.0f, 100.0f});
}

void init(GLOBAL_T *ALL)
{
    ALL->pic = malloc(sizeof(IMG_T) * 20);
    init_window(ALL);
    init_background(ALL);
    init_menu(ALL);
    init_music_button(ALL);
    init_cursor(ALL);
    init_music_button(ALL);
    init_replay(ALL);
    init_ninja(ALL);
    init_setting(ALL);
}
