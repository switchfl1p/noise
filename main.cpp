#include <perlin.hpp>

// Perlin noise - smooth, natural looking
// Simplex noise - faster than Perlin, less directional artifacts
// Fractional Brownian Motion (fBM) - layered noise for detail

int main() {
    Perlin perlin(3);
    perlin.generateHeightMap(100, 100, 10.0f);
}