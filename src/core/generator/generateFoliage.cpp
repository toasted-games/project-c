#include <iostream>
#include "generateFoliage.h"

GenerateFoliage::GenerateFoliage()
{
    memset(foliage, -1, sizeof(foliage));

    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            foliage[y][x] = GetTileValue(x, y);
        }
    }
}

foliageValue GenerateFoliage::GetTileValue(int x, int y)
{
    if (generatedTerrain.terrain[y][x] == WATER)
    {
        return NO_FOLIAGE;
    }
    else if (generatedTerrain.terrain[y][x] == SAND)
    {
        return DESERT_BUSH;
    }
    else if (generatedTerrain.terrain[y][x] == GRASS)
    {
        return GRASS_BUSH;
    }
    else if (generatedTerrain.terrain[y][x] == ROCKS)
    {
        return ROCKS_BUSH;
    }
    else if (generatedTerrain.terrain[y][x] == MOUNTAINS)
    {
        return MOUNTAINS_BUSH;
    }

    return NO_FOLIAGE;
}