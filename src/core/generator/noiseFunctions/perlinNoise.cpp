#include <math.h>
#include "perlinNoise.hpp"

/* Function to linearly interpolate between a0 and a1
 * Weight w should be in the range [0.0, 1.0]
 */
float PerlinNoise::interpolate(float a0, float a1, float w)
{
    // // Use this cubic interpolation [[Smoothstep]], for a smooth appearance:
    // return (a1 - a0) * (3.0 - w * 2.0) * w * w + a0;

    // Use [[Smootherstep]] for an even smoother result with a second derivative equal to zero on boundaries:
    return (float)((a1 - a0) * ((w * (w * 6.0 - 15.0) + 10.0) * w * w * w) + a0);
}

/* Create pseudorandom direction vector
 */
vector2 PerlinNoise::randomGradient(int ix, int iy)
{
    // No precomputed gradients mean this works for any number of grid coordinates
    const unsigned w = 8 * sizeof(unsigned);
    const unsigned s = w / 2; // rotation width
    unsigned a = ix, b = iy;
    a *= 3284157443;
    b ^= a << s | a >> (w - s);
    b *= 1911520717;
    a ^= b << s | b >> (w - s);
    a *= 2048419325;
    float random = (float)(a * (3.14159265 / ~(~0u >> 1))); // in [0, 2*Pi]
    vector2 v;
    v.x = (float)cos(random);
    v.y = (float)sin(random);
    return v;
}

// Computes the dot product of the distance and gradient vectors.
float PerlinNoise::dotGridGradient(int ix, int iy, float x, float y)
{
    // Get gradient from integer coordinates
    vector2 gradient = randomGradient(ix, iy);

    // Compute the distance vector
    float dx = x - (float)ix;
    float dy = y - (float)iy;

    // Compute the dot-product
    return (dx * gradient.x + dy * gradient.y);
}

// Compute Perlin noise at coordinates x, y
float PerlinNoise::perlin(float x, float y)
{
    // Determine grid cell coordinates
    int x0 = (int)floor(x);
    int x1 = x0 + 1;
    int y0 = (int)floor(y);
    int y1 = y0 + 1;

    // Determine interpolation weights
    // Could also use higher order polynomial/s-curve here
    float sx = x - (float)x0;
    float sy = y - (float)y0;

    // Interpolate between grid point gradients
    float n0, n1, ix0, ix1, value;

    n0 = dotGridGradient(x0, y0, x, y);
    n1 = dotGridGradient(x1, y0, x, y);
    ix0 = interpolate(n0, n1, sx);

    n0 = dotGridGradient(x0, y1, x, y);
    n1 = dotGridGradient(x1, y1, x, y);
    ix1 = interpolate(n0, n1, sx);

    value = interpolate(ix0, ix1, sy);
    return value * 0.5f + 0.5f; // Will return in range -1 to 1. To make it in range 0 to 1, multiply by 0.5 and add 0.5
}

float PerlinNoise::perlinNoise2D(float x, float y, int octaves, float persistence, float frequency)
{
    float total = 0.0,  // Total value of all octaves added together
        maxValue = 0.0, // Used for normalizing result to 0.0 - 1.0
        amplitude = 1;  // Starting amplitude

    for (int i = 0; i < octaves; i++)
    {
        float noiseValue = perlin(x * frequency, y * frequency);
        total += noiseValue * amplitude;
        maxValue += amplitude;
        amplitude *= persistence;
        frequency *= 2.0;
    }

    return total / maxValue;
}