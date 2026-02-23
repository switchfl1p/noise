#pragma once
#include <glm/glm.hpp>

class Perlin{
    public:
        Perlin(int seed);

        float perlin2D(float x, float y);

        std::array<int, 512> genPermTable(int seed);

        glm::vec2 getGradient(int x, int y);

        void reseed(int seed);
    
    private:
        std::array<int, 512> perm_table;

        std::array<glm::vec2, 8> gradients = {
            glm::vec2( 1,  0),
            glm::vec2(-1,  0),
            glm::vec2( 0,  1),
            glm::vec2( 0, -1),
            glm::normalize(glm::vec2( 1,  1)),
            glm::normalize(glm::vec2(-1,  1)),
            glm::normalize(glm::vec2( 1, -1)),
            glm::normalize(glm::vec2(-1, -1))
        };
};
