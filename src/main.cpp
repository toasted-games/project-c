#include <iostream>
#include <string>
#include <raylib.h>

#include "./button.h"

#include "generator/core/dom.h"

using namespace std;

int main(int, char **)
{
    std::cout << "Hello, from project-c!\n";

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(30);

    // DOM dom;

    // dom.load("menu.tmpl");

    Button button("Click me!", {
                                   100,
                                   100,
                                   200,
                                   50,
                                   BLUE,
                                   RED,
                               });

    button.onClick([]()
                   { std::cout << "Button clicked!" << std::endl; });

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        button.update();

        // dom.render();

        EndDrawing();
    }

    CloseWindow();
}
