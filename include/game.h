/*
** EPITECH PROJECT, 2023
** game.h
** File description:
** structure
*/

#ifndef GAME_
    #define GAME_
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stdio.h>

typedef struct PARAMETER {
    sfVideoMode mode;
    sfRenderWindow *win;
    sfEvent event;
} PARAMETER_T;

typedef struct IMG {
    sfTexture *text;
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f pos;
    sfVector2f size;
} IMG_T;

typedef struct GAME {
    sfVector2i mpos;
    sfIntRect rect;
    int currentF;
    int currentF1;
    int currentF2;
    int currentF3;
    float FTime;
    float FTime1;
    float FTime2;
    float FTime3;
    float f;
    float f1;
    float f2;
    float f3;
    int countdead;
    sfClock *moving_clock;
    sfClock *anim;
} GAME_T;

typedef struct SCORE {
    sfFont* font;
    sfText* scoretxt;
    sfText* nbrtxt;
    int score;
    char *count;
} SCORE_T;

typedef struct MUSIC {
    sfMusic *theme;
    sfMusic *shuriken;
    sfMusic *dead;
    sfMusic *dead2;
    sfMusic *dead3;
} MUSIC_T;

typedef struct GLOBAL {
    PARAMETER_T settings;
    IMG_T *pic;
    GAME_T play;
    MUSIC_T music;
    GAME_T game;
    SCORE_T score;
} GLOBAL_T;

#endif
