/*
** EPITECH PROJECT, 2023
** setting menu
** File description:
** setting difficulty
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/my.h"

char *int_to_string(int n, char *result)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char temp;

    while (n > 0) {
        result[i] = (n % 10) + '0';
        n /= 10;
        i++;
    }
    result[i] = '\0';
    k = i - 1;
    while (j < k) {
        temp = result[j];
        result[j] = result[k];
        result[k] = temp;
        j++;
        k--;
    }
    return result;
}

void init_setting(GLOBAL_T *ALL)
{
    ALL->pic[17].text = sfTexture_createFromFile("image/setting.png", NULL);
    ALL->pic[17].sprite = sfSprite_create();
    ALL->pic[17].pos.x = 10;
    ALL->pic[17].pos.y = 10;
    sfSprite_setPosition(ALL->pic[17].sprite, ALL->pic[17].pos);
    sfSprite_setTexture(ALL->pic[17].sprite, ALL->pic[17].text, sfTrue);
    ALL->pic[18].text = sfTexture_createFromFile("image/set_menu.jpg", NULL);
    ALL->pic[18].sprite = sfSprite_create();
    sfSprite_setTexture(ALL->pic[18].sprite, ALL->pic[18].text, sfTrue);
    ALL->pic[19].text = sfTexture_createFromFile("image/life.png", NULL);
    ALL->pic[19].sprite = sfSprite_create();
    ALL->pic[19].pos.x = 1800;
    ALL->pic[19].pos.y = 0;
    sfSprite_setPosition(ALL->pic[19].sprite, ALL->pic[19].pos);
    sfSprite_setTexture(ALL->pic[19].sprite, ALL->pic[19].text, sfTrue);
}

void setting_menu(GLOBAL_T *ALL)
{
    while (sfRenderWindow_isOpen(ALL->settings.win)) {
        open_window(ALL);
        sfRenderWindow_drawSprite(ALL->settings.win, ALL->pic[18].sprite,
            NULL);
        sfRenderWindow_setMouseCursorVisible(ALL->settings.win, sfTrue);
        sfRenderWindow_display(ALL->settings.win);
        select_difficulty(ALL);
    }
}

void select_difficulty(GLOBAL_T *ALL)
{
    sfFloatRect setting = sfSprite_getGlobalBounds(ALL->pic[17].sprite);
    sfFloatRect difficult = sfSprite_getGlobalBounds(ALL->pic[18].sprite);

    ALL->play.mpos = sfMouse_getPositionRenderWindow(ALL->settings.win);
    if (sfFloatRect_contains(&setting, ALL->play.mpos.x, ALL->play.mpos.y)) {
        if (ALL->settings.event.type == sfEvtMouseButtonPressed)
            setting_menu(ALL);
    }
    if (sfFloatRect_contains(&difficult, ALL->play.mpos.x, ALL->play.mpos.y)) {
        if (ALL->settings.event.type == sfEvtMouseButtonPressed)
            play(ALL);
    }
}
