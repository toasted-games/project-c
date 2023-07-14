#include <iostream>
#include <math.h>
#include <iostream>
#include "raylib.h"

#include "core/generator/generateTerrain.h"
#include "core/generator/generateFoliage.h"
#include "core/generator/makeTerrainImage.h"

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
    const int squareSize = 3;

    const int screenWidth = columns * squareSize;
    const int screenHeight = rows * squareSize;

    InitWindow(screenWidth, screenHeight, "Kwadraty zależne od wartości");

    SetTargetFPS(60);

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

                // Przypisanie koloru w zależności od wartości
                switch (value)
                {
                case 0:
                    color = BLUE;
                    break;
                case 1:
                    color = YELLOW;
                    break;
                case 2:
                    color = GREEN;
                    break;
                case 3:
                    color = GRAY;
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
            }
        }

        EndDrawing();
    }

    CloseWindow();

    // makeTerrainImage(generatedTerrain.terrain);
}
