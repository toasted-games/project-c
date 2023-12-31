#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <raylib.h>

enum MenuState
{
    MAIN,
    PLAY,
    MULTIPLAYER,
    SETTINGS,
    GAME
};

class Menu
{
public:
    MenuState state;

    Menu();
    void update();

private:
    void renderMain();
    void renderSettings();

    float screenWidth;
    float screenHeight;

    Image background;
    Texture2D backgroundTexture;

    Shader backgroundBlur;

    Rectangle getMenuWrapper();
    void renderButtons(Rectangle container);
};

#endif