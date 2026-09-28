#include "player.h"
#include <iostream>

int main(){
    Player p1;
    Player p2(5,5);

    std::cout << "p1 health: " << p1.getHealth() << "\n"; //20
    std::cout << "p2 pos: " << p2.getX() << ", " << p2.getY() << "\n";
    
    p1.attack(p2);
    
    std::cout << "p2 health after attack: " << p2.getHealth() << "\n"; //15

    return 0;
}
