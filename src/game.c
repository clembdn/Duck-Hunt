/*
** EPITECH PROJECT, 2023
** game.c
** File description:
** game
*/
#include "include/my.h"

static void reset_pos(GLOBAL_T *ALL)
{
    sfMusic *dead1 = sfMusic_createFromFile("image/dead.ogg");

    if (ALL->pic[10].pos.x > 1950) {
        sfMusic_play(dead1);
        ALL->pic[10].pos = (sfVector2f){-100, random_nbr(100, 900)};
    }
    if (ALL->pic[14].pos.x > 1950) {
        sfMusic_play(dead1);
        ALL->pic[14].pos = (sfVector2f){-100, random_nbr(100, 900)};
    }
    if (ALL->pic[16].pos.x > 1950) {
        sfMusic_play(dead1);
        ALL->pic[16].pos = (sfVector2f){-100, random_nbr(100, 900)};
    }
}

static void ninja_anim2(GLOBAL_T *ALL)
{
    sfIntRect ninjadie = {0, 0, 96, 157};
    sfIntRect life = {353, 0, 118, 116};

    if (ALL->game.f2 >= ALL->game.FTime2) {
        ALL->game.f2 = 0.0f;
        ninjadie.left += ALL->game.currentF2 * 90;
        sfSprite_setTextureRect(ALL->pic[15].sprite, ninjadie);
        ALL->game.currentF2 = (ALL->game.currentF2 + 1) % 5;
    }
    if (ALL->pic[10].pos.x > 1950 || ALL->pic[14].pos.x > 1950 ||
        ALL->pic[16].pos.x > 1950) {
        reset_pos(ALL);
        ALL->game.countdead += 1;
        life.left -= ALL->game.currentF3 * 115;
        sfSprite_setTextureRect(ALL->pic[19].sprite, life);
        ALL->game.currentF3 = (ALL->game.currentF3 + 1) % 4;
    }
}

void ninja_anim(GLOBAL_T *ALL)
{
    sfIntRect ninjaattack = {0, 0, 120, 113};
    sfIntRect ninjarun = {0, 0, 116, 115};

    if (ALL->game.f >= ALL->game.FTime) {
        ALL->game.f = 0.0f;
        ninjaattack.left += ALL->game.currentF * 120;
        sfSprite_setTextureRect(ALL->pic[10].sprite, ninjaattack);
        sfSprite_setTextureRect(ALL->pic[14].sprite, ninjaattack);
        ALL->game.currentF = (ALL->game.currentF + 1) % 2;
    }
    if (ALL->game.f3 >= ALL->game.FTime3) {
        ALL->game.f3 = 0.0f;
        ninjarun.left += ALL->game.currentF3 * 116;
        sfSprite_setTextureRect(ALL->pic[16].sprite, ninjarun);
        ALL->game.currentF3 = (ALL->game.currentF3 + 1) % 4;
    }
    ninja_anim2(ALL);
}

static void if_dead(GLOBAL_T *ALL)
{
    sfFloatRect replay = sfSprite_getGlobalBounds(ALL->pic[6].sprite);
    sfFloatRect exit = sfSprite_getGlobalBounds(ALL->pic[5].sprite);

    ALL->play.mpos = sfMouse_getPositionRenderWindow(ALL->settings.win);
    if (ALL->settings.event.type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(&replay, ALL->play.mpos.x, ALL->play.mpos.y))
            play(ALL);
        if (sfFloatRect_contains(&exit, ALL->play.mpos.x, ALL->play.mpos.y))
            sfRenderWindow_close(ALL->settings.win);
    }
}

static void replay(GLOBAL_T *ALL)
{
    while (sfRenderWindow_isOpen(ALL->settings.win)) {
        open_window(ALL);
        sfRenderWindow_drawSprite(ALL->settings.win, ALL->pic[4].sprite, NULL);
        sfRenderWindow_drawSprite(ALL->settings.win, ALL->pic[5].sprite, NULL);
        sfRenderWindow_drawSprite(ALL->settings.win, ALL->pic[6].sprite, NULL);
        sfRenderWindow_setMouseCursorVisible(ALL->settings.win, sfTrue);
        sfRenderWindow_display(ALL->settings.win);
        if_dead(ALL);
    }
}

static void return_lobby2(GLOBAL_T *ALL)
{
    sfFloatRect ninja3 = sfSprite_getGlobalBounds(ALL->pic[16].sprite);

    if (sfFloatRect_contains(&ninja3, ALL->play.mpos.x, ALL->play.mpos.y)) {
        sfMusic_play(ALL->music.dead2);
        sfSprite_setPosition(ALL->pic[15].sprite, ALL->pic[16].pos);
        ALL->score.score++;
        ALL->pic[16].pos = (sfVector2f){-100, random_nbr(100, 900)};
        game_function(ALL);
    }
}

void return_lobby(GLOBAL_T *ALL)
{
    sfFloatRect ninja = sfSprite_getGlobalBounds(ALL->pic[10].sprite);
    sfFloatRect ninja2 = sfSprite_getGlobalBounds(ALL->pic[14].sprite);

    sfMusic_play(ALL->music.shuriken);
    ALL->play.mpos = sfMouse_getPositionRenderWindow(ALL->settings.win);
    if (sfFloatRect_contains(&ninja, ALL->play.mpos.x, ALL->play.mpos.y)) {
        sfMusic_play(ALL->music.dead);
        sfSprite_setPosition(ALL->pic[15].sprite, ALL->pic[10].pos);
        ALL->score.score += 1;
        ALL->pic[10].pos = (sfVector2f){-100, random_nbr(100, 900)};
        game_function(ALL);
    }
    if (sfFloatRect_contains(&ninja2, ALL->play.mpos.x, ALL->play.mpos.y)) {
        sfMusic_play(ALL->music.dead);
        sfSprite_setPosition(ALL->pic[15].sprite, ALL->pic[14].pos);
        ALL->score.score += 1;
        ALL->pic[14].pos = (sfVector2f){-100, random_nbr(100, 900)};
        game_function(ALL);
    }
    return_lobby2(ALL);
}

void reset(GLOBAL_T *ALL)
{
    ALL->pic[10].pos = (sfVector2f){-100, random_nbr(100, 900)};
    ALL->pic[14].pos = (sfVector2f){-100, random_nbr(100, 900)};
    ALL->pic[16].pos = (sfVector2f){-100, random_nbr(100, 900)};
}

void game_function2(GLOBAL_T *ALL)
{
    int tab[8] = {1, 10, 14, 16, 15, 3, 2, 19};

    for (int i = 0; i < 8; i++) {
        sfRenderWindow_drawSprite(ALL->settings.win,
            ALL->pic[tab[i]].sprite, NULL);
    }
    sfRenderWindow_setMouseCursorVisible(ALL->settings.win, sfFalse);
    ALL->score.count = int_to_string(ALL->score.score, ALL->score.count);
    sfText_setString(ALL->score.scoretxt, "SCORE :");
    sfText_setString(ALL->score.nbrtxt, ALL->score.count);
    sfRenderWindow_drawText(ALL->settings.win, ALL->score.scoretxt, NULL);
    sfRenderWindow_drawText(ALL->settings.win, ALL->score.nbrtxt, NULL);
    sfRenderWindow_display(ALL->settings.win);
    if (ALL->settings.event.type == sfEvtMouseButtonPressed)
        return_lobby(ALL);
    if (ALL->game.countdead == 3)
        replay(ALL);
}

void game_function(GLOBAL_T *ALL)
{
    ALL->game.anim = sfClock_create();
    while (sfRenderWindow_isOpen(ALL->settings.win)) {
        open_window(ALL);
        ALL->game.f += sfClock_getElapsedTime(ALL->game.anim).microseconds
            / 1000000.0f;
        ALL->game.f2 += sfClock_getElapsedTime(ALL->game.anim).microseconds
            / 1000000.0f;
        ALL->game.f3 += sfClock_getElapsedTime(ALL->game.anim).microseconds
            / 1000000.0f;
        sfClock_restart(ALL->game.anim);
        ALL->pic[10].pos.x += 5;
        ALL->pic[14].pos.x += 2;
        ALL->pic[16].pos.x += 6;
        sfSprite_setPosition(ALL->pic[10].sprite, ALL->pic[10].pos);
        sfSprite_setPosition(ALL->pic[14].sprite, ALL->pic[14].pos);
        sfSprite_setPosition(ALL->pic[16].sprite, ALL->pic[16].pos);
        ninja_anim(ALL);
        game_function2(ALL);
    }
}
