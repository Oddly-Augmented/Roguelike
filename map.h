/* 
Map.h
Define Map of the world
*/

#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <iostream>

class Map {
    private:
        std::vector<std::string> grid;
        int width;
        int height;

    public:
        Map(int w, int h); //Map size
        void print() const; //Print map
        void print(int playerX, int playerY) const; // Print overload to display player 
        bool isWalkable(int x, int y) const; // Where the player can walk
};

#endif