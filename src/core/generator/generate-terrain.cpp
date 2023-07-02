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

    int randomStartX = 0; // rand() % size;
    int randomStartY = 0; // rand() % size;

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
        std::cout << "previousValue: " << previousValue << std::endl;
        terrainValue value = static_cast<terrainValue>(rand() % MOUNTAINS);
        terrain[y][x] = value;
    }
    else
    {
        int around[] = {-1, -1, -1, -1};

        if (y - 1 > 0)
        {
            around[0] = terrain[y - 1][x];
        }
        if (y + 1 < size)
        {
            around[1] = terrain[y + 1][x];
        }
        if (x - 1 > 0)
        {
            around[2] = terrain[y][x - 1];
        }
        if (x + 1 < size)
        {
            around[3] = terrain[y][x + 1];
        }

        int max = around[0], min = around[0];
        for (int i = 0; i < 4; i++)
        {
            if (around[i] != -1)
            {
                if (around[i] < min)
                {
                    min = i;
                }
                if (around[i] > max)
                {
                    max = i;
                }
            }
        }

        int value = previousValue + int(round(sin(rand())));

        // std::cout << "max: " << max << " min: " << min << " value: " << value << std::endl;
        if (max != -1 && min != -1 && max - min >= 2)
        {
            value = round((max - min) / 2);
        }

        // int diffrentMax = abs(max - value);
        // int diffrentMin = abs(min - value);

        // std::cout << std::endl
        //           << "diffrentMax: " << diffrentMax << " diffrentMin: " << diffrentMin << std::endl;

        if (value > MOUNTAINS)
        {
            value = MOUNTAINS;
        }
        else if (value < WATER)
        {
            value = WATER;
        }

        // std::cout << "max: " << max << " min: " << min << " value: " << value << " previous: " << previousValue << std::endl;

        terrain[y][x] = static_cast<terrainValue>(value);
    }

    if (x - 1 >= 0 && terrain[y][x - 1] == -1)
    {
        // std::cout << "left\n";
        GetTileValue(y, x - 1, terrain[y][x]);
    }
    if (x + 1 < size && terrain[y][x + 1] == -1)
    {
        // std::cout << "right\n";
        GetTileValue(y, x + 1, terrain[y][x]);
    }
    if (y - 1 >= 0 && terrain[y - 1][x] == -1)
    {
        // std::cout << "up\n";
        GetTileValue(y - 1, x, terrain[y][x]);
    }
    if (y + 1 < size && terrain[y + 1][x] == -1)
    {
        // std::cout << "down\n";
        GetTileValue(y + 1, x, terrain[y][x]);
    }

    return;
}