#include <iostream>

#include "core/generator/generate-terrain.h"
#include "core/generator/makeTerrainImage.h"
#include "core/generator/noiseTesting/5.cpp"

int main(int, char **)
{
    // GenerateTerrain asd;

    // makeTerrainImage(asd.terrain);

    // perlin5();

    float array[size][size];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            array[i][j] = (perlin((float)(i * 0.1), (float)(j * 0.1))) * 0.5 + 0.5;
        }
    }

    terrainValue array2[size][size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            // std::cout << array[i][j] << "\t";
            if (array[i][j] < 0.3)
            {
                array2[i][j] = WATER;
            }
            else if (array[i][j] < 0.5)
            {
                array2[i][j] = SAND;
            }
            else if (array[i][j] < 0.7)
            {
                array2[i][j] = GRASS;
            }
            else if (array[i][j] < 0.9)
            {
                array2[i][j] = ROCKS;
            }
            else
            {
                array2[i][j] = MOUNTAINS;
            }
        }
        // std::cout << "\n";
    }

    makeTerrainImage(array2);
}
