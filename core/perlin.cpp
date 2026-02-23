#include <perlin.hpp>
#include <random>
#include <algorithm>

Perlin::Perlin(int seed) : perm_table(genPermTable(seed)){};

float Perlin::perlin2D(float x, float y){
    //find which grid cell we're in
    int cell_x = glm::floor(x);
    int cell_y = glm::floor(y);

    //find local position within that grid cell
    float local_x = x - cell_x;
    float local_y = y - cell_y;
}

std::array<int, 512> Perlin::genPermTable(int seed){
    std::array<int, 512> perm_table;

    for(int i = 0; i <= 255; i++){
        perm_table[i] = i;
    }

    //create random engine using a seed
    std::mt19937 rand_engine(seed);

    //shuffle the first 256 elements using the random engine
    std::shuffle(perm_table.begin(), perm_table.begin() + 256, rand_engine);

    //duplicate the elements into the rest of the array
    for(int i = 256; i < 512; i++){
        perm_table[i] = perm_table[i - 256];
    }

    return perm_table;
}

glm::vec2 Perlin::getGradient(int x, int y){

}

void Perlin::reseed(int seed){
    perm_table = genPermTable(seed);
}

/*
function perlin(x, y):

    # STEP 1: Find which grid cell we're in
    cellX = floor(x)
    cellY = floor(y)

    # STEP 2: Find our position within that cell (0 to 1)
    localX = x - cellX
    localY = y - cellY

    # STEP 3: Get the gradient vector for each of the 4 corners
    # you use a permutation table here to look up a gradient
    # based on the corner's integer coordinates
    gradTL = getGradient(cellX,     cellY + 1)
    gradTR = getGradient(cellX + 1, cellY + 1)
    gradBL = getGradient(cellX,     cellY)
    gradBR = getGradient(cellX + 1, cellY)

    # STEP 4: Compute the vector from each corner to our point
    # then dot it with that corner's gradient
    dotTL = dot(gradTL, (localX,     localY - 1))
    dotTR = dot(gradTR, (localX - 1, localY - 1))
    dotBL = dot(gradBL, (localX,     localY))
    dotBR = dot(gradBR, (localX - 1, localY))

    # STEP 5: Apply the fade curve to smooth the local coordinates
    u = fade(localX)
    v = fade(localY)

    # STEP 6: Interpolate between the 4 dot products
    # first interpolate along the bottom and top edges
    # then interpolate between those two results vertically
    bottom = lerp(dotBL, dotBR, u)
    top    = lerp(dotTL, dotTR, u)
    result = lerp(bottom, top, v)

    return result 
*/