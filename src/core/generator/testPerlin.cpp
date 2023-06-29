#include <cstdio>
#include <random>
#include <functional>
#include <iostream>
#include <fstream>
#include <cmath>

template <typename T>
class Vec2
{
public:
    Vec2() : x(T(0)), y(T(0)) {}
    Vec2(T xx, T yy) : x(xx), y(yy) {}
    Vec2 operator*(const T &r) const { return Vec2(x * r, y * r); }
    T x, y;
};

typedef Vec2<float> Vec2f;

template <typename T = float>
inline T lerp(const T &lo, const T &hi, const T &t)
{
    return lo * (1 - t) + hi * t;
}

inline float smoothstep(const float &t) { return t * t * (3 - 2 * t); }

class ValueNoise
{
public:
    ValueNoise(unsigned seed = 2016)
    {
        std::mt19937 gen(seed);
        std::uniform_real_distribution<float> distrFloat;
        auto randFloat = std::bind(distrFloat, gen);

        // create an array of random values and initialize the permutation table
        for (unsigned k = 0; k < kMaxTableSize; ++k)
        {
            r[k] = randFloat();
            permutationTable[k] = k;
        }

        // shuffle values of the permutation table
        std::uniform_int_distribution<unsigned> distrUInt;
        auto randUInt = std::bind(distrUInt, gen);
        for (unsigned k = 0; k < kMaxTableSize; ++k)
        {
            unsigned i = randUInt() & kMaxTableSizeMask;
            std::swap(permutationTable[k], permutationTable[i]);
            permutationTable[k + kMaxTableSize] = permutationTable[k];
        }
    }

    float eval(Vec2f &p) const
    {
        int xi = std::floor(p.x);
        int yi = std::floor(p.y);

        float tx = p.x - xi;
        float ty = p.y - yi;

        int rx0 = xi & kMaxTableSizeMask;
        int rx1 = (rx0 + 1) & kMaxTableSizeMask;
        int ry0 = yi & kMaxTableSizeMask;
        int ry1 = (ry0 + 1) & kMaxTableSizeMask;

        // random values at the corners of the cell using the permutation table
        const float &c00 = r[permutationTable[permutationTable[rx0] + ry0]];
        const float &c10 = r[permutationTable[permutationTable[rx1] + ry0]];
        const float &c01 = r[permutationTable[permutationTable[rx0] + ry1]];
        const float &c11 = r[permutationTable[permutationTable[rx1] + ry1]];

        // remapping of tx and ty using the Smoothstep function
        float sx = smoothstep(tx);
        float sy = smoothstep(ty);

        // linearly interpolate values along the x axis
        float nx0 = lerp(c00, c10, sx);
        float nx1 = lerp(c01, c11, sx);

        // linearly interpolate the nx0/nx1 along they y axis
        return lerp(nx0, nx1, sy);
    }

    static const unsigned kMaxTableSize = 256;
    static const unsigned kMaxTableSizeMask = kMaxTableSize - 1;
    float r[kMaxTableSize];
    unsigned permutationTable[kMaxTableSize * 2];
};

void test_perlin()
{
    float frequency = (float)0.128;
    const int imageWidth = 500, imageHeight = imageWidth;
    float noiseMap[imageWidth * imageHeight];
#if 0
    // generate white noise
    unsigned seed = 2016;
    std::mt19937 gen(seed);
    std::uniform_real_distribution<float> distr;
    auto dice = std::bind(distr, gen); // std::function<float()>

    for (unsigned j = 0; j < imageHeight; ++j)
    {
        for (unsigned i = 0; i < imageWidth; ++i)
        {
            // generate a float in the range [0:1]
            noiseMap[j * imageWidth + i] = dice();
        }
    }
#else
    // generate value noise
    ValueNoise noise;
    for (unsigned j = 0; j < imageHeight; j++)
    {
        for (unsigned i = 0; i < imageWidth; i++)
        {
            // generate a float in the range [0:1]
            noiseMap[j * imageWidth + i] = noise.eval(Vec2f(i, j) * frequency);
        }
    }
#endif

    // output noise map to image
    std::ofstream ofs;
    ofs.open("./noise.ppm", std::ios::out | std::ios::binary);
    ofs << "P6\n"
        << imageWidth << " " << imageHeight << "\n255\n";
    for (int k = 0; k < imageWidth * imageHeight; k++)
    {
        int p1, p2, p3;

        if (noiseMap[k] > 0.9)
        {
            p1 = 50;
            p2 = 50;
            p3 = 50;
        }
        else if (noiseMap[k] > 0.7)
        {
            p1 = 100;
            p2 = 100;
            p3 = 100;
        }
        else if (noiseMap[k] > 0.6)
        {
            p1 = 50;
            p2 = 128;
            p3 = 50;
        }
        else if (noiseMap[k] > 0.4)
        {
            p1 = 0;
            p2 = 255;
            p3 = 0;
        }
        else if (noiseMap[k] > 0.2)
        {
            p1 = 255;
            p2 = 255;
            p3 = 0;
        }
        else if (noiseMap[k] > 0)
        {
            p1 = 0;
            p2 = 0;
            p3 = 255;
        }
        else
        {
            p1 = 0;
            p2 = 0;
            p3 = 0;
        }

        ofs << (char)p1 << (char)p2 << (char)p3;
    }
    ofs.close();

    // delete[] noiseMap;

    // return 0;
}