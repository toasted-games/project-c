#include <iostream>

#include <raylib.h>
#include "layout/menu/menu.h"

int main(int, char **)
{
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    InitWindow(screenWidth, screenHeight, "Project C");

    SetWindowState(FLAG_WINDOW_UNDECORATED);

    SetExitKey(KEY_NULL);

    Menu menu;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        menu.update();
        EndDrawing();
    }
}
