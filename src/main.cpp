#include <iostream>
#include "core/generator/generate-terrain.h"
#include "core/generator/makeTerrainImage.h"

int main(int, char **)
{
    std::cout << "Hello, from project-c!\n";

    GenerateTerrain asd;

    makeTerrainImage(asd.terrain);
}
