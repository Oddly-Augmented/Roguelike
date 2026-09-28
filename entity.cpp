#include "entity.h"

Entity::Entity(int startX, int startY, int startHealth) : x(startX), y(startY), health(startHealth){}

Entity::~Entity() {}

int Entity::getX() const {return x;}
int Entity::getY() const {return y;}
int Entity::getHealth() const {return health;}

void Entity::setPosition(int newX, int newY){
    x = newX;
    y = newY;
}

void Entity::takeDamage(int amount){
    health -= amount;
    if (health < 0) health = 0;
}
