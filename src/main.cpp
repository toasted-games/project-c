#include <iostream>
#include <math.h>
#include <iostream>
#include "raylib.h"

#include "core/generator/generateTerrain.h"
#include "core/generator/generateFoliage.h"
#include "core/generator/makeTerrainImage.h"
#include "core/generator/loadImages.h"

int main(int, char **)
{
    GenerateTerrain generatedTerrain;
    GenerateFoliage generatedFoliage;

    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < size; j++)
    //     {
    //         std::cout << generatedFoliage.foliage[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    const int rows = size;
    const int columns = size;
    const int squareSize = 10;

    const int screenWidth = columns * squareSize;
    const int screenHeight = rows * squareSize;

    InitWindow(screenWidth, screenHeight, "Project-C");
    // InitWindow(400, 400, "Project-C");

    SetTargetFPS(60);

    LoadImages loadedImages;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                int value = generatedTerrain.terrain[i][j];
                Color color;
                Texture2D texture;

                // Przypisanie koloru w zależności od wartości
                switch (value)
                {
                case 0:
                    color = BLUE;
                    break;
                case 1:
                    color = YELLOW;
                    texture = loadedImages.deadbush_128x128;
                    break;
                case 2:
                    color = GREEN;
                    texture = loadedImages.bush_128x128;
                    break;
                case 3:
                    color = GRAY;
                    texture = loadedImages.tree_128x128;
                    break;
                case 4:
                    color = BLACK;
                    break;
                default:
                    color = WHITE;
                    break;
                }

                // Rysowanie kwadratu o odpowiednim kolorze
                DrawRectangle(j * squareSize, i * squareSize, squareSize, squareSize, color);

                if (value > 0 && value < 4)
                {
                    DrawTexturePro(texture,
                                   {0.0f, 0.0f, (float)texture.width, (float)texture.height},
                                   {(float)j * squareSize, (float)i * squareSize, squareSize, squareSize},
                                   {0.0f, 0.0f},
                                   0,
                                   WHITE);
                }
            }
        }

        EndDrawing();
    }

    CloseWindow();

    // makeTerrainImage(generatedTerrain.terrain);
}
