/* 
map.cpp
Construct Map of the world
*/
#include "map.h"
#include "player.h"

Map::Map(int w, int h) : width(w), height(h){
    //Every row as a wall of '#'
    grid.resize(height, std::string(width, '#'));

    // Carve out rectangular room, except the edges
    for (int y = 1; y < height - 1; y++){
        for (int x = 1; x < width -1; x++){
            grid[y][x] = '.';
        }
    }
}

// -------------------- MAP Print --------------------
void Map::print() const{
    for (const std::string& row : grid){
        std::cout << row << "\n";
    }
}

// Display Map with Player
void Map::print(int playerX, int playerY) const{
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            if (x == playerX && y == playerY){
                std::cout << '@';
            }
            else {
                std::cout << grid[y][x];
            }
        }
        std::cout << "\n";
    }
}


// -------------------- MAP Walkable --------------------

// Where the player can walk
bool Map::isWalkable(int x, int y) const{
    if (x < 0 || x >= width || y < 0 || y >= height){
        return false;
    }
    return grid[y][x] == '.';
}