#include <vector>
#include <cmath>

// int hash(int x, int y)
// {
//     // Hash the grid cell coordinates
//     int seed = 12345;
//     int hash = seed;
//     hash = hash * 1103515245 + x;
//     hash = hash * 1103515245 + y;
//     hash ^= hash >> 10;
//     hash *= 1103515245;
//     hash ^= hash >> 10;
//     hash *= 1103515245;
//     hash ^= hash >> 10;
//     return hash;
// }

// float fade(float t)
// {
//     // Smooth the interpolation function
//     return t * t * t * (t * (t * 6 - 15) + 10);
// }

// float lerp(float a, float b, float t)
// {
//     // Linearly interpolate between two values
//     return (1 - t) * a + t * b;
// }

// float perlin(float x, float y)
// {
//     std::cout << "x: " << x << " y: " << y << std::endl;

//     // Define a grid of random gradient vectors
//     int gradientVectors[4][2] = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

//     // Determine the grid cell coordinates
//     int x0 = floor(x);
//     int x1 = x0 + 1;
//     int y0 = floor(y);
//     int y1 = y0 + 1;

//     std::cout << "x0: " << x0 << " x1: " << x1 << " y0: " << y0 << " y1: " << y1 << std::endl;
//     std::cout << "hash(x0, y0): " << hash(x0, y0) << " hash(x0, y1): " << hash(x0, y1) << " hash(x1, y0): " << hash(x1, y0) << " hash(x1, y1): " << hash(x1, y1) << std::endl;
//     std::cout << "gradientVectors[hash(x0, y0)][0]: " << gradientVectors[hash(x0, y0)][0] << std::endl;
//     // Compute the dot products between the gradient vectors and the distance vectors
//     float dot00 = gradientVectors[hash(x0, y0)][0] * (x - x0) + gradientVectors[hash(x0, y0)][1] * (y - y0);
//     float dot01 = gradientVectors[hash(x0, y1)][0] * (x - x0) + gradientVectors[hash(x0, y1)][1] * (y - y1);
//     float dot10 = gradientVectors[hash(x1, y0)][0] * (x - x1) + gradientVectors[hash(x1, y0)][1] * (y - y0);
//     float dot11 = gradientVectors[hash(x1, y1)][0] * (x - x1) + gradientVectors[hash(x1, y1)][1] * (y - y1);

//     // Interpolate the dot products to get a smooth value
//     float u = fade(x - x0);
//     float v = fade(y - y0);
//     float a = lerp(dot00, dot10, u);
//     float b = lerp(dot01, dot11, u);
//     float c = lerp(a, b, v);

//     return c;
// }

// Define a hash function to map coordinates to gradient vectors
int hash(int x, int y)
{
    int seed = 12345;
    int hash = seed;
    hash ^= x + 0x9e3779b9 + (hash << 6) + (hash >> 2);
    hash ^= y + 0x9e3779b9 + (hash << 6) + (hash >> 2);
    return hash;
}

// Define a function to linearly interpolate between two values
float lerp(float a, float b, float t)
{
    return round((1 - t) * a + t * b);
}

// Define a function to compute the dot product between a gradient vector and a distance vector
float dotProduct(int gradientX, int gradientY, float x, float y)
{
    float dx = x - gradientX;
    float dy = y - gradientY;
    return dx * gradientX + dy * gradientY;
}

// Define the Perlin noise function
float perlin(float x, float y)
{
    // Define a grid of random gradient vectors
    int gradientVectors[4][2] = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

    // Determine the grid cell coordinates
    int x0 = floor(x);
    int x1 = x0 + 1;
    int y0 = floor(y);
    int y1 = y0 + 1;

    // Compute the dot products between the gradient vectors and the distance vectors
    float dot00 = dotProduct(gradientVectors[hash(x0, y0) % 4][0], gradientVectors[hash(x0, y0) % 4][1], x, y);
    float dot01 = dotProduct(gradientVectors[hash(x0, y1) % 4][0], gradientVectors[hash(x0, y1) % 4][1], x, y - 1);
    float dot10 = dotProduct(gradientVectors[hash(x1, y0) % 4][0], gradientVectors[hash(x1, y0) % 4][1], x - 1, y);
    float dot11 = dotProduct(gradientVectors[hash(x1, y1) % 4][0], gradientVectors[hash(x1, y1) % 4][1], x - 1, y - 1);

    // Interpolate between the dot products to get the final noise value
    float tx = x - x0;
    float ty = y - y0;
    float u = lerp(dot00, dot10, tx);
    float v = lerp(dot01, dot11, tx);
    float noiseValue = lerp(u, v, ty);

    // Normalize the noise value to the range [-1, 1]
    float normalizedValue = noiseValue / 1.5f;

    // Scale the noise value to the desired range
    float scaledValue = (normalizedValue + 1.0f) * 2.5f;

    return scaledValue;
}

float generatePerlinNoise(int width1, int height1, float frequency)
{
    const int width = 20, height = width;

    float noiseMap[height][width];
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            noiseMap[j][i] = perlin((float)i * frequency, (float)j * frequency);
        }
    }

    for (int j = 0; j < height; j++)
    {
        std::cout << "ASD: ";
        for (int i = 0; i < width; i++)
        {
            std::cout << round(noiseMap[j][i]) << "\t";
        }
        std::cout << std::endl;
    }

    return 1.0f;
}