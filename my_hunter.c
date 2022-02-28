/*
** EPITECH PROJECT, 2021
** my_hunter.c
** File description:
** my_hunter
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

int wallpaper(t_Structure *fs)
{
    fs->sprite.my_galaxy = sfSprite_create();
    fs->texture.my_texture =
    sfTexture_createFromFile("files/images/galaxy.jpg", NULL);
    sfSprite_setTexture(fs->sprite.my_galaxy,
    fs->texture.my_texture, sfFalse);
    return 0;
}

int kirby_sprite(t_Structure *fs)
{
    fs->sprite.my_kirby = sfSprite_create();
    fs->texture.my_texture2 =
    sfTexture_createFromFile("files/images/kirby.png", NULL);
    sfVector2f kirbypos = {0, 0};
    sfSprite_setTexture(fs->sprite.my_kirby,
    fs->texture.my_texture2, sfFalse);
    sfSprite_setPosition(fs->sprite.my_kirby, kirbypos);
    return 0;
}

int kirby_race(t_Structure *fs)
{
    fs->music.my_kirbyrace =
    sfMusic_createFromFile("files/music/kirbyrace.ogg");
    sfMusic_play(fs->music.my_kirbyrace);
    sfMusic_setLoop(fs->music.my_kirbyrace, sfTrue);
    return 0;
}

int open_window(t_Structure *fs)
{
    sfVideoMode mode = {1920, 1080, 32};
    fs->window.my_window =
    sfRenderWindow_create(mode, "My_Hunter", sfFullscreen, 0);
    fs->clock.my_clock = sfClock_create();
    sfRenderWindow_setFramerateLimit(fs->window.my_window, 144);
    sfRenderWindow_setMouseCursorVisible(fs->window.my_window, sfFalse);
    kirby_race(fs);
    wallpaper(fs);
    kirby_sprite(fs);
    legacy_cursor(fs);
    draw_sprite(fs);
    sfRenderWindow_destroy(fs->window.my_window);
    sfMusic_destroy(fs->music.my_kirbyrace);
    return 0;
}
