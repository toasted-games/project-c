#include <iostream>
#include <cmath>
#include <cstdlib>
#include "generateTerrain.h"
#include "noiseFunctions/perlinNoise.h"

GenerateTerrain::GenerateTerrain()
{
    srand((unsigned)time(NULL));

    memset(terrain, -1, sizeof(terrain));

    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            terrain[y][x] = GetTileValue(x, y);
        }
    }
}

terrainValue GenerateTerrain::GetTileValue(int x, int y)
{
    int octaves = 1;
    float frequency = 1, persistence = 0.5;

    PerlinNoise perlin;
    float value = perlin.perlinNoise2D(x * 0.1, y * 0.1, octaves, persistence, frequency);

    if (value < 0.3)
    {
        return WATER;
    }
    else if (value < 0.5)
    {
        return SAND;
    }
    else if (value < 0.7)
    {
        return GRASS;
    }
    else if (value < 0.9)
    {
        return ROCKS;
    }
    else
    {
        return MOUNTAINS;
    }

    return EMPTY;
}
