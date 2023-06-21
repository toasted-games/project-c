#ifndef UX_BUTTON_H
#define UX_BUTTON_H

#include <iostream>
#include <string>
#include <raylib.h>
#include <functional>

struct Position
{
    float x;
    float y;
};

struct Style
{
    Position position = {
        0,
        0,
    };
    float width = 100;
    float height = 50;

    Color color;
    Color backgroundColor;
};

class Button
{
public:
    Button();
    Button(std::string text);
    Button(std::string text, Style style);

    void onClick(std::function<void()> callback);
    void onHover(std::function<void()> callback);

    void update();

private:
    Style style;
    std::string text;

    std::function<void()> click;
    std::function<void()> hover;

    void drawButton();
    void handleEvents();

    bool checkClick();
    bool checkHover();
};

#endif // UX_BUTTON_H
