#include <iostream>
#include <cmath>
#include <cstdlib>
#include "generate-terrain.h"

// const int size = 10;
// int posiibleTerrainValues[] = {0, 1, 2, 3, 4, 5}; -3 -2 -1  0  1  2  3

// int generate_terrain()
// {
//     srand((unsigned)time(NULL));

//     std::cout << "Hello, from generate-terrain!\n";

//     int terrain[size][size];

//     // std::cout << sizeof(terrain) / sizeof(terrain[0]);
//     // std::cout << sizeof(terrain[0]) / sizeof(terrain[0][0]);

//     int randomStartX = rand() % size;
//     int randomStartY = rand() % size;
//     int randomTerrainValue = posiibleTerrainValues[rand() % sizeof(posiibleTerrainValues) / sizeof(posiibleTerrainValues[0])];

//     terrain[randomStartX][randomStartY] = randomTerrainValue;

//     generate_one_tile(randomStartX, randomStartY, terrain);

//     std::cout << "\nrandomStartX: "
//               << randomStartX << " randomStartY: " << randomStartY << "\nrandomTerrainValue: " << randomTerrainValue << "\n";

//     for (int i = 0; i < size; i++)
//     {
//         std::cout << "\n";
//         for (int j = 0; j < size; j++)
//         {
//             std::cout << terrain[i][j] << "\t";
//         }
//     }

//     return 0;
// }

// int generate_one_tile(int x, int y, int terrain[size][size])
// {
//     if (x < 0 || x >= size || y < 0 || y >= size)
//     {
//         return 0;
//     }

//     int nextValue = sin() * 100;

//     return 0;
// }

GenerateTerrain::GenerateTerrain()
{
    std::cout << "Hello, from GenerateTerrain!\n";
    std::cout << "size: " << size << "\n";

    memset(terrain, 0, sizeof(terrain));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << terrain[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

terrainValue GenerateTerrain::GetTileValue(int x, int y)
{
    // std::cout << "Hello, from get tile value!\n";

    return EMPTY;
}