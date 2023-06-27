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

void GenerateTerrain::GetTileValue(int y, int x, terrainValue previousValue)
{
    std::cout << "x: " << x << " y: " << y << "\n";
    std::cout << "previousValue: " << previousValue << "\n";
    if (previousValue == -1)
    {
        terrainValue value = static_cast<terrainValue>(rand() % MOUNTAINS);
        terrain[y][x] = value;
        std::cout << "value: " << value << " terrain[x][y]: " << terrain[y][x] << "\n";

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
        terrain[y][x] = previousValue;

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