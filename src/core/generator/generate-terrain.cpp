#include <iostream>
#include <cmath>
#include <cstdlib>

int generate_terrain()
{
    srand((unsigned)time(NULL));

    std::cout << "Hello, from generate-terrain!\n";

    const int size = 10;

    unsigned int terrain[size][size];
    int posiibleTerrainValues[] = {0, 1, 2, 3, 4, 5};

    // std::cout << sizeof(terrain) / sizeof(terrain[0]);
    // std::cout << sizeof(terrain[0]) / sizeof(terrain[0][0]);

    int randomStartX = rand() % size;
    int randomStartY = rand() % size;
    int randomTerrainValue = posiibleTerrainValues[rand() % sizeof(posiibleTerrainValues) / sizeof(posiibleTerrainValues[0])];

    terrain[randomStartX][randomStartY] = randomTerrainValue;

    std::cout << "\nrandomStartX: "
              << randomStartX << " randomStartY: " << randomStartY << "\nrandomTerrainValue: " << randomTerrainValue << "\n";

    for (int i = 0; i < size; i++)
    {
        std::cout << "\n";
        for (int j = 0; j < size; j++)
        {
            std::cout << terrain[i][j] << "\t";
        }
    }

    return 0;
}