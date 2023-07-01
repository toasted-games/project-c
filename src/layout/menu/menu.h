#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <raylib.h>

enum MenuState
{
    MAIN,
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

    Rectangle getMenuWrapper();
    void renderButtons(Rectangle container);
};

#endif