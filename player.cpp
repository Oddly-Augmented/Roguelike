/* 
player.cpp
The player class IS-A Entity
Player starts with 20 health at the cords 0,0
*/
#include "player.h"
#include <iostream>

Player::Player(int startX, int startY) 
    : Entity(startX, startY, 20) // Player start with 20 health
{}

Player::Player()
    : Entity(0, 0, 20)
{}

void Player::attack(Entity& target){
    int damage =5;
    std::cout << "Player attacks for " << damage << " damage!\n";
    target.takeDamage(damage);
}
