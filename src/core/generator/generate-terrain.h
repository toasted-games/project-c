enum terrainValue
{
    EMPTY = -1,
    WATER = 0,
    SAND,
    GRASS,
    ROCKS,
    MOUNTAINS,
};

const int size = 10;

class GenerateTerrain
{
private:
    terrainValue terrain[size][size];
    
    void GetTileValue(int x, int y, terrainValue previousValue);

public:
    GenerateTerrain();
};