#include <perlin.hpp>

int main() {
    Perlin perlin(3);
    perlin.generateHeightMap(100, 100, 10.0f);
}