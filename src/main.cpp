#include <iostream>
#include <string>
#include <raylib.h>
#include "generator/core/dom.h"

using namespace std;

int main(int, char **)
{
    std::cout << "Hello, from project-c!\n";
    std::cout << GetScreenWidth() << GetScreenHeight();
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));

    // DOM dom;

    // dom.load("menu.tmpl");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // dom.render();

        EndDrawing();
    }

    CloseWindow();
}
