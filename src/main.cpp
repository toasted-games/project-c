#include <iostream>

#include <raylib.h>
#include "layout/menu/menu.h"

int main(int, char **)
{
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    InitWindow(screenWidth, screenHeight, "Project C");

    SetWindowState(FLAG_WINDOW_UNDECORATED);
    SetConfigFlags(FLAG_MSAA_4X_HINT);

    SetExitKey(KEY_NULL);

    Menu menu;

    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        menu.update();
        EndDrawing();
    }

    return 0;
}
