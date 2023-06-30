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

const int size = 100;

class GenerateTerrain
{
private:
    void GetTileValue(int x, int y, int previousValue);

public:
    terrainValue terrain[size][size];

    GenerateTerrain();
};

#endif // GENERATE_TERRAIN_H