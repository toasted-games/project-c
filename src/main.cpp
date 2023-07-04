#include <iostream>
#include <math.h>
#include <iostream>
#include <raylib.h>

#include "core/generator/generateTerrain.hpp"
#include "core/generator/makeTerrainImage.hpp"

int main(int, char **)
{
    GenerateTerrain asd;

    makeTerrainImage(asd.terrain);
}
