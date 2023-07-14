#include "generateTerrain.h"

#ifndef GENERATE_FOLIAGE_H
#define GENERATE_FOLIAGE_H

enum foliageValue
{
    NO_FOLIAGE = -1,
    DESERT_BUSH = 0,
    GRASS_BUSH = 1,
    GRASS_TREE = 2,
    ROCKS_BUSH = 3,
    ROCKS_TREE = 4,
    MOUNTAINS_BUSH = 5,
};

class GenerateFoliage
{
private:
    foliageValue GetTileValue(int x, int y);

    GenerateTerrain generatedTerrain;

public:
    foliageValue foliage[size][size];
    GenerateFoliage();
};

#endif // GENERATE_FOLIAGE_H