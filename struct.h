/*
** EPITECH PROJECT, 2021
** struct.h
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include <SFML/Graphics.h>
    #include <SFML/Window/Export.h>
    #include <SFML/Window/Event.h>
    #include <SFML/Window/VideoMode.h>
    #include <SFML/Window/WindowHandle.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/System/Export.h>
    #include <SFML/Audio.h>

typedef struct s_Sprite {
    sfSprite *my_galaxy;
    sfSprite *my_kirby;
    sfSprite *my_legacy;

}t_Sprite;

typedef struct s_Texture {
    sfTexture *my_texture;
    sfTexture *my_texture2;
    sfTexture *my_texture3;

}t_Texture;

typedef struct s_Music {
    sfMusic *my_kirbyrace;

}t_Music;

typedef struct s_Vector {
    sfVector2f my_kirbypos;
    sfVector2f my_cursor;

}t_Vector;

typedef struct s_OWindow {
    sfRenderWindow *my_window;

}t_OWindow;

typedef struct s_Event {
    sfEvent my_event;

}t_Event;

typedef struct s_Clock {
    sfClock *my_clock;

}t_Clock;

typedef struct s_Time {
    sfTime *my_time;

}t_Time;

typedef struct s_Structure {
    t_Sprite sprite;
    t_Texture texture;
    t_Music music;
    t_Vector vector;
    t_OWindow window;
    t_Event event;
    t_Clock clock;
    t_Time time;

}t_Structure;

int wallpaper(t_Structure *fs);
int kirby_sprite(t_Structure *fs);
int open_window(t_Structure *fs);
int legacy_cursor(t_Structure *fs);
int event(t_Structure *fs);
int draw_sprite(t_Structure *fs);
void kirby_is_moving(t_Structure *fs);
void left_click(t_Structure *fs);

#endif
