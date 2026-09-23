#include "map.h"
#include "player.h"

int main(){
    Map m(20, 10);
    Player p(5, 3);
    m.print(p.getX(), p.getY());
    return 0;
}