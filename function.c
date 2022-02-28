/*
** EPITECH PROJECT, 2021
** function.c
** File description:
** function
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/WindowHandle.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Export.h>
#include <SFML/Audio.h>
#include "struct.h"
#include <stdlib.h>

int event(t_Structure *fs)
{
    while (sfRenderWindow_pollEvent(fs->window.my_window,
    &fs->event.my_event)) {
        if (fs->event.my_event.type == sfEvtClosed) {
            sfRenderWindow_close(fs->window.my_window);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfRenderWindow_close(fs->window.my_window);
        }
        if (fs->event.my_event.type == sfEvtMouseButtonPressed) {
            left_click(fs);
        }
    }
    return 0;
}

void kirby_is_moving(t_Structure *fs)
{
    sfTime tkirby;
    float sec;

    tkirby = sfClock_getElapsedTime(fs->clock.my_clock);
    sec = tkirby.microseconds / 1;
    if (sec > 0.01) {
        fs->vector.my_kirbypos.x += 5;
        sfSprite_setPosition(fs->sprite.my_kirby, fs->vector.my_kirbypos);
        if (fs->vector.my_kirbypos.x >= 1920) {
            fs->vector.my_kirbypos.x = -300;
            fs->vector.my_kirbypos.y = rand() % 850;
            sfClock_restart(fs->clock.my_clock);
        }
    }
}

int draw_sprite(t_Structure *fs)
{
    while (sfRenderWindow_isOpen(fs->window.my_window)) {
        event(fs);
        sfRenderWindow_drawSprite(fs->window.my_window,
        fs->sprite.my_galaxy, NULL);
        sfRenderWindow_drawSprite(fs->window.my_window,
        fs->sprite.my_kirby, NULL);
        kirby_is_moving(fs);
        sfVector2f cursor;
        cursor.x = sfMouse_getPosition((sfWindow*)fs->
        window.my_window).x -10;
        cursor.y = sfMouse_getPosition((sfWindow*)fs->
        window.my_window).y -10;
        sfSprite_setPosition(fs->sprite.my_legacy, cursor);
        sfRenderWindow_drawSprite(fs->window.my_window,
        fs->sprite.my_legacy, NULL);
        sfRenderWindow_display(fs->window.my_window);
    }
}

int legacy_cursor(t_Structure *fs)
{
    fs->sprite.my_legacy = sfSprite_create();
    fs->texture.my_texture3 =
    sfTexture_createFromFile("files/images/cursor.png", NULL);
    sfSprite_setTexture(fs->sprite.my_legacy,
    fs->texture.my_texture3, sfFalse);
    sfSprite_setScale(fs->sprite.my_legacy, (sfVector2f) {1, 1});
    return 0;
}

void left_click(t_Structure *fs)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow*)fs->window.my_window);
    if ((mouse.x >= fs->vector.my_kirbypos.x &&
    mouse.x <= (fs->vector.my_kirbypos.x + 220))) {
        if ((mouse.y >= fs->vector.my_kirbypos.y &&
        mouse.y <= (fs->vector.my_kirbypos.y + 210))) {
            fs->vector.my_kirbypos.x = -400;
            fs->vector.my_kirbypos.y = rand() % 850;
            sfRenderWindow_drawSprite(fs->window.my_window,
            fs->sprite.my_kirby, NULL);
        }
    }
}
