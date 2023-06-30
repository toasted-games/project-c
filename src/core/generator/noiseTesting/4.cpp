// #include <iostream>
// #include <cmath>

// int hash4(int x, int y)
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
//     std::cout << "hash(x0, y0): " << hash4(x0, y0) << " hash(x0, y1): " << hash4(x0, y1) << " hash(x1, y0): " << hash4(x1, y0) << " hash(x1, y1): " << hash4(x1, y1) << std::endl;
//     std::cout << "gradientVectors[hash(x0, y0)][0]: " << gradientVectors[hash4(x0, y0)][0] << std::endl;
//     // Compute the dot products between the gradient vectors and the distance vectors
//     float dot00 = gradientVectors[hash4(x0, y0)][0] * (x - x0) + gradientVectors[hash4(x0, y0)][1] * (y - y0);
//     float dot01 = gradientVectors[hash4(x0, y1)][0] * (x - x0) + gradientVectors[hash4(x0, y1)][1] * (y - y1);
//     float dot10 = gradientVectors[hash4(x1, y0)][0] * (x - x1) + gradientVectors[hash4(x1, y0)][1] * (y - y0);
//     float dot11 = gradientVectors[hash4(x1, y1)][0] * (x - x1) + gradientVectors[hash4(x1, y1)][1] * (y - y1);

//     // Interpolate the dot products to get a smooth value
//     float u = fade(x - x0);
//     float v = fade(y - y0);
//     float a = lerp(dot00, dot10, u);
//     float b = lerp(dot01, dot11, u);
//     float c = lerp(a, b, v);

//     return c;
// }
