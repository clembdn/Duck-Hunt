/*
** EPITECH PROJECT, 2023
** B-CPE-100-NCE-1-1-cpoolday13-clement.boudon
** File description:
** task02.c
*/
#include "include/my.h"

int open_window(GLOBAL_T *ALL)
{
    while (sfRenderWindow_pollEvent(ALL->settings.win, &ALL->settings.event)) {
        sfRenderWindow_clear(ALL->settings.win, sfWhite);
        if (ALL->settings.event.type == sfEvtClosed)
            sfRenderWindow_close(ALL->settings.win);
        if (ALL->settings.event.type == sfEvtMouseMoved) {
            ALL->pic[2].pos.x = ALL->settings.event.mouseMove.x - 75;
            ALL->pic[2].pos.y = ALL->settings.event.mouseMove.y - 75;
            sfSprite_setPosition(ALL->pic[2].sprite, ALL->pic[2].pos);
            ALL->pic[3].pos.x = ALL->settings.event.mouseMove.x - 75;
            ALL->pic[3].pos.y = 600;
            sfSprite_setPosition(ALL->pic[3].sprite, ALL->pic[3].pos);
        }
    }
    return 0;
}

static void detect_button_music(GLOBAL_T *ALL)
{
    sfFloatRect music_off = sfSprite_getGlobalBounds(ALL->pic[12].sprite);
    sfFloatRect music_on = sfSprite_getGlobalBounds(ALL->pic[13].sprite);

    ALL->play.mpos = sfMouse_getPositionRenderWindow(ALL->settings.win);
    if (sfFloatRect_contains(&music_on, ALL->play.mpos.x, ALL->play.mpos.y)) {
        sfRenderWindow_drawSprite(ALL->settings.win, ALL->pic[9].sprite, NULL);
        if (ALL->settings.event.type == sfEvtMouseButtonPressed)
            sfMusic_setVolume(ALL->music.theme, 100);
    }
    if (sfFloatRect_contains(&music_off, ALL->play.mpos.x, ALL->play.mpos.y)) {
        sfRenderWindow_drawSprite(ALL->settings.win, ALL->pic[7].sprite, NULL);
        if (ALL->settings.event.type == sfEvtMouseButtonPressed)
            sfMusic_setVolume(ALL->music.theme, 0);
    }
}

void detect_button(GLOBAL_T *ALL)
{
    sfFloatRect play_now = sfSprite_getGlobalBounds(ALL->pic[11].sprite);

    ALL->play.mpos = sfMouse_getPositionRenderWindow(ALL->settings.win);
    if (sfFloatRect_contains(&play_now, ALL->play.mpos.x, ALL->play.mpos.y)) {
        sfRenderWindow_drawSprite(ALL->settings.win, ALL->pic[8].sprite, NULL);
        if (ALL->settings.event.type == sfEvtMouseButtonPressed) {
            ALL->score.score = 0;
            ALL->game.countdead = 0;
            reset(ALL);
            game_function(ALL);
        }
    }
    detect_button_music(ALL);
}

void destroy_all(GLOBAL_T *ALL)
{
    sfRenderWindow_destroy(ALL->settings.win);
    for (int i = 0; i != 20; i++) {
        sfTexture_destroy(ALL->pic[i].text);
        sfSprite_destroy(ALL->pic[i].sprite);
    }
    sfMusic_destroy(ALL->music.theme);
    sfMusic_destroy(ALL->music.dead);
    sfMusic_destroy(ALL->music.dead2);
    sfText_destroy(ALL->score.scoretxt);
    sfFont_destroy(ALL->score.font);
    sfClock_destroy(ALL->game.anim);
    sfClock_destroy(ALL->game.moving_clock);
}

void play(GLOBAL_T *ALL)
{
    sfMusic_play(ALL->music.theme);
    ALL->play.mpos = sfMouse_getPositionRenderWindow(ALL->settings.win);
    while (sfRenderWindow_isOpen(ALL->settings.win)) {
        open_window(ALL);
        sfRenderWindow_drawSprite(ALL->settings.win,
            ALL->pic[11].sprite, NULL);
        sfRenderWindow_drawSprite(ALL->settings.win,
            ALL->pic[12].sprite, NULL);
        sfRenderWindow_drawSprite(ALL->settings.win,
            ALL->pic[13].sprite, NULL);
        sfRenderWindow_setMouseCursorVisible(ALL->settings.win, sfTrue);
        sfRenderWindow_drawSprite(ALL->settings.win, ALL->pic[0].sprite, NULL);
        detect_button(ALL);
        sfRenderWindow_drawSprite(ALL->settings.win,
            ALL->pic[17].sprite, NULL);
        select_difficulty(ALL);
        sfRenderWindow_display(ALL->settings.win);
    }
}

static int flag_h(int argc, char **argv)
{
    int fd = open("help.txt", O_RDONLY);
    char buffer;
    int i = 0;
    ssize_t bytesRead;

    if (argv[1][1] != 'h')
        return 84;
    bytesRead = read(fd, &buffer, 1);
    while (bytesRead > 0) {
        write(1, &buffer, 1);
        i++;
        bytesRead = read(fd, &buffer, 1);
    }
    close(fd);
    return 0;
}

int main(int argc, char **argv)
{
    GLOBAL_T ALL;

    if (argc == 2)
        return flag_h(argc, argv);
    if (argc == 1) {
        init(&ALL);
        play(&ALL);
    }
    return 0;
}
