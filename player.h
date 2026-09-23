/* 
player.h
Define the player class, 
*/

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    int x;
    int y;
public:
    Player(int startX, int startY);
    int getX() const;
    int getY() const;
    void setPosition(int newX, int newY);
};


#endif