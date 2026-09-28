/* 
player.h
Define the player class, 
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity
{
public:
    Player(int startX, int startY);
    Player();

    void attack(Entity& target) override;
};


#endif
