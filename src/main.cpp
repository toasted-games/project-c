#include <iostream>

#include <raylib.h>
#include "layout/menu/menu.h"

int main(int, char **)
{
    InitWindow(800, 600, "Project C");

    Menu menu;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        menu.update();
        EndDrawing();
    }
}
