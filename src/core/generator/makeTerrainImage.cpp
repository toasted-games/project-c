#include <iostream>
#include <cmath>
#include <cstdlib>
#include "makeTerrainImage.h"
#include "generate-terrain.h"

void makeTerrainImage(terrainValue terrain[size][size])
{
    FILE *imageFile;

    FILE *file;
    errno_t err = fopen_s(&file, "image.png", "wb");
    if (err != 0)
    {
        perror("ERROR: Cannot open output file");
        exit(EXIT_FAILURE);
    }

    imageFile = file;
    if (imageFile == NULL)
    {
        perror("ERROR: Cannot open output file");
        exit(EXIT_FAILURE);
    }

    fprintf(imageFile, "P6\n");                // P6 filetype
    fprintf(imageFile, "%d %d\n", size, size); // dimensions
    fprintf(imageFile, "255\n");               // Max pixel

    int index = 0;
    unsigned char arrayPixels[size * size * 3];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            switch (terrain[i][j])
            {
            case 0:
                arrayPixels[index] = 0;
                arrayPixels[index + 1] = 0;
                arrayPixels[index + 2] = 255;
                break;
            case 1:
                arrayPixels[index] = 255;
                arrayPixels[index + 1] = 255;
                arrayPixels[index + 2] = 0;
                break;
            case 2:
                arrayPixels[index] = 0;
                arrayPixels[index + 1] = 255;
                arrayPixels[index + 2] = 0;
                break;
            case 3:
                arrayPixels[index] = 100;
                arrayPixels[index + 1] = 100;
                arrayPixels[index + 2] = 100;
                break;
            case 4:
                arrayPixels[index] = 50;
                arrayPixels[index + 1] = 50;
                arrayPixels[index + 2] = 50;
                break;
            default:
                arrayPixels[index] = 0;
                arrayPixels[index + 1] = 0;
                arrayPixels[index + 2] = 0;
                break;
            }

            index += 3;
        }
    }

    // for (int i = 0; i < size * size * 3; i++)
    // {
    //     std::cout << i << ": " << int(arrayPixels[i]) << " ";
    //     if (i % 3 == 2)
    //     {
    //         std::cout << std::endl;
    //     }
    // }

    fwrite(arrayPixels, 1, size * size * 3, imageFile);
    fclose(imageFile);
}
