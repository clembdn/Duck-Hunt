/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** day9 task2
*/

#ifndef MY_
    #define MY_

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include "game.h"

int random_nbr(int min, int max);
void game_function(GLOBAL_T *ALL);
void game_function2(GLOBAL_T *ALL);
int open_window(GLOBAL_T *ALL);
void detect_button(GLOBAL_T *ALL);
void init(GLOBAL_T *ALL);
void init_menu(GLOBAL_T *ALL);
void init_music_button(GLOBAL_T *ALL);
void init_cursor(GLOBAL_T *ALL);
void init_ninja(GLOBAL_T *ALL);
void init_replay(GLOBAL_T *ALL);
void play(GLOBAL_T *ALL);
void return_lobby(GLOBAL_T *ALL);
void ninja_anim(GLOBAL_T *ALL);
void init_setting(GLOBAL_T *ALL);
void init_setting2(GLOBAL_T *ALL);
void select_difficulty(GLOBAL_T *ALL);
char *int_to_string(int n, char *result);
void reset(GLOBAL_T *ALL);
void setting_menu(GLOBAL_T *ALL);
void destroy_all(GLOBAL_T *ALL);

#endif
