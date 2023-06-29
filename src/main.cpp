// #include <iostream>
// #include "core/generator/generate-terrain.h"
// #include "core/generator/makeTerrainImage.h"
// // #include "core/generator/testPerlin.cpp"
// #include "core/generator/testPerlin2.cpp"

// int main(int, char **)
// {
//     // GenerateTerrain asd;

//     // makeTerrainImage(asd.terrain);

//     // test_perlin();

//     int width = 10;
//     int height = 10;
//     float frequency = 0.1f;
//     // float **noiseMap = generatePerlinNoise(width, height, frequency);
//     // generatePerlinNoise(width, height, frequency);

//     // for (int y = 0; y < height; y++)
//     // {
//     //     std::cout << "[";
//     //     for (int x = 0; x < width; x++)
//     //     {
//     //         std::cout << perlin(x * frequency, y * frequency) << ", ";
//     //     }
//     //     std::cout << "]\n";
//     // }
//     // std::cout << perlin(1, 1);
//     generatePerlinNoise(width, height, frequency);
// }

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

// Define the hash function for the gradient vectors
int hash(int x, int y)
{
    int seed = 1013;
    int hash = x * seed + y * (seed + 1);
    srand(hash);
    return rand();
}

// Define the dot product function
float dotProduct(int gradientX, int gradientY, float x, float y)
{
    float dx = x - gradientX;
    float dy = y - gradientY;
    return dx * gradientX + dy * gradientY;
}

// Define the Perlin noise function
#include <functional>

float perlin(float x, float y)
{
    // Define a grid of random gradient vectors
    int gradientVectors[4][2] = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

    // Define the hash function for the gradient vectors
    std::hash<int> hash_fn;
    auto hash = [&](int x, int y)
    { return hash_fn(x * 1000000 + y); };

    // Determine the grid cell coordinates
    int x0 = static_cast<int>(floor(x));
    int x1 = x0 + 1;
    int y0 = static_cast<int>(floor(y));
    int y1 = y0 + 1;

    // Compute the dot products between the gradient vectors and the distance vectors
    float dot00 = dotProduct(gradientVectors[hash(x0, y0) % 4][0], gradientVectors[hash(x0, y0) % 4][1], x, y);
    float dot01 = dotProduct(gradientVectors[hash(x0, y1) % 4][0], gradientVectors[hash(x0, y1) % 4][1], x, y - 1);
    float dot10 = dotProduct(gradientVectors[hash(x1, y0) % 4][0], gradientVectors[hash(x1, y0) % 4][1], x - 1, y);
    float dot11 = dotProduct(gradientVectors[hash(x1, y1) % 4][0], gradientVectors[hash(x1, y1) % 4][1], x - 1, y - 1);

    // Interpolate between the dot products to get the final noise value
    float tx = x - x0;
    float ty = y - y0;
    float u = tx * tx * (3 - 2 * tx);
    float v = ty * ty * (3 - 2 * ty);
    float dot0 = dot00 * (1 - u) + dot10 * u;
    float dot1 = dot01 * (1 - u) + dot11 * u;
    return (dot0 * (1 - v) + dot1 * v + 1) / 2;
}

int main()
{
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Define the size of the 2D array
    const int ROWS = 200, COLS = ROWS;

    // Create the 2D array and fill it with Perlin noise values
    float arr[ROWS][COLS];
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            arr[i][j] = perlin(i / 10.0, j / 10.0);
        }
    }

    unsigned char water[3] = {0, 0, 255};
    unsigned char sand[3] = {255, 255, 0};
    unsigned char grass[3] = {0, 255, 0};
    unsigned char rock[3] = {128, 128, 128};
    unsigned char snow[3] = {255, 255, 255};

    // Convert the 2D array to a 1D image buffer
    unsigned char buffer[ROWS * COLS * 3];
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int index = (i * COLS + j) * 3;
            float height = arr[i][j] * 255;
            unsigned char *color;
            if (height < 20)
            {
                color = water;
            }
            else if (height < 70)
            {
                color = sand;
            }
            else if (height < 90)
            {
                color = grass;
            }
            else if (height < 150)
            {
                color = rock;
            }
            else
            {
                color = snow;
            }
            buffer[index] = color[0];
            buffer[index + 1] = color[1];
            buffer[index + 2] = color[2];
        }
    }

    // Write the image buffer to a PNG file using file I/O
    ofstream outfile("terrain.ppm", ios::binary);
    outfile << "P6\n"
            << COLS << " " << ROWS << "\n255\n";
    outfile.write(reinterpret_cast<char *>(buffer), ROWS * COLS * 3);
    outfile.close();

    return 0;
}