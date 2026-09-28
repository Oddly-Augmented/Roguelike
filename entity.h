#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
protected:
    int x;
    int y;
    int health;

public:
    Entity(int startX, int startY, int startHealth);
    virtual ~Entity(); // virtual destructor

    int getX() const;
    int getY() const;
    int getHealth() const;
    void setPosition(int newX, int newY);

    virtual void takeDamage(int amount);
    virtual void attack(Entity& target) = 0; // pure virtual — makes Entity abstract
};

#endif
