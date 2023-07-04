#ifndef GENERATE_TERRAIN_H
#define GENERATE_TERRAIN_H

enum terrainValue
{
    EMPTY = -1,
    WATER = 0,
    SAND = 1,
    GRASS = 2,
    ROCKS = 3,
    MOUNTAINS = 4,
};

// const int size = 10;
const int size = 256;

class GenerateTerrain
{
private:
    terrainValue GetTileValue(int x, int y);

public:
    terrainValue terrain[size][size];

    GenerateTerrain();
};

#endif // GENERATE_TERRAIN_H