#ifndef PERLINNOISE_HPP
#define PERLINNOISE_HPP

typedef struct
{
    float x, y;
} vector2;

class PerlinNoise
{
private:
    float interpolate(float a0, float a1, float w);
    vector2 randomGradient(int ix, int iy);
    float dotGridGradient(int ix, int iy, float x, float y);
    float perlin(float x, float y);

public:
    float perlinNoise2D(float x, float y, int octaves, float persistence, float frequency);
};

#endif // PERLINNOISE_HPP