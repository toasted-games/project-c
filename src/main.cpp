#include <iostream>
#include "core/generator/generate-terrain.h"
#include "core/generator/makeTerrainImage.h"

int main(int, char **)
{
    GenerateTerrain asd;

    makeTerrainImage(asd.terrain);
}