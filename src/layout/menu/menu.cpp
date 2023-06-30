#include "menu.h"

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

Menu::Menu()
{
}

void Menu::update()
{
    // Rectangle menuBar = {0, 0, 100, 20};
    GuiLabel({0, 0, 100, 20}, "Hello World!");

    bool buttonPressed = GuiButton({0, 20, 100, 20}, "Button");

    if (buttonPressed)
    {
        std::cout << "Button pressed!" << std::endl;
        CloseWindow();
    }
}