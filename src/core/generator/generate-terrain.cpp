#include <iostream>
#include <cmath>
#include <cstdlib>
#include "generate-terrain.h"

GenerateTerrain::GenerateTerrain()
{
    srand((unsigned)time(NULL));

    std::cout << "Hello, from GenerateTerrain!\n";
    std::cout << "size: " << size << "\n";

    memset(terrain, -1, sizeof(terrain));

    int randomStartX = rand() % size;
    int randomStartY = rand() % size;

    std::cout << "randomStartX: " << randomStartX << " randomStartY: " << randomStartY << "\n";

    GetTileValue(randomStartY, randomStartX, terrain[randomStartY][randomStartX]);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << terrain[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

void GenerateTerrain::GetTileValue(int y, int x, int previousValue)
{
    if (previousValue == -1)
    {
        std::cout << "previousValue == -1\n";
        terrainValue value = static_cast<terrainValue>(rand() % MOUNTAINS);
        terrain[y][x] = value;

        if (x - 1 >= 0 && terrain[y][x - 1] == -1)
        {
            GetTileValue(y, x - 1, terrain[y][x]);
        }
        if (x + 1 < size && terrain[y][x + 1] == -1)
        {
            GetTileValue(y, x + 1, terrain[y][x]);
        }
        if (y - 1 >= 0 && terrain[y - 1][x] == -1)
        {
            GetTileValue(y - 1, x, terrain[y][x]);
        }
        if (y + 1 < size && terrain[y + 1][x] == -1)
        {
            GetTileValue(y + 1, x, terrain[y][x]);
        }
    }
    else
    {
        // std::cout << "previousValue != -1\n";
        int value = previousValue + int(round(sin(rand())));
        // std::cout << "previousValue: " << previousValue << "\tvalue: " << value;

        if (value > MOUNTAINS)
        {
            value = MOUNTAINS;
        }
        else if (value < WATER)
        {
            value = WATER;
        }
        terrain[y][x] = static_cast<terrainValue>(value);
        // std::cout << "\tterrain: " << terrain[y][x] << "\n";
        if (x - 1 >= 0 && terrain[y][x - 1] == -1)
        {
            GetTileValue(y, x - 1, terrain[y][x]);
        }
        if (x + 1 < size && terrain[y][x + 1] == -1)
        {
            GetTileValue(y, x + 1, terrain[y][x]);
        }
        if (y - 1 >= 0 && terrain[y - 1][x] == -1)
        {
            GetTileValue(y - 1, x, terrain[y][x]);
        }
        if (y + 1 < size && terrain[y + 1][x] == -1)
        {
            GetTileValue(y + 1, x, terrain[y][x]);
        }
    }
}