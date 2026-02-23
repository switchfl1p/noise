#include <iostream>
#include <perlin.hpp>
#include <iomanip>

int main() {
    Perlin perlin(3);

    for(int y = 0; y < 10; y++){
        for(int x = 0; x < 10; x++){
            float value = perlin.perlin2D(x / 10.0f, y / 10.0f);
            std::cout << std::fixed << std::setprecision(2) << value << " ";
        }
        std::cout << "\n";
    }
}