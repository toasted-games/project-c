#include <iostream>
#include <math.h>
#include <iostream>
#include <raylib.h>

#include "core/generator/generateTerrain.h"
#include "core/generator/makeTerrainImage.h"

int main(int, char **)
{
    GenerateTerrain generatedTerrain;

    makeTerrainImage(generatedTerrain.terrain);
}
