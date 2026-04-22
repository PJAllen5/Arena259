#include <iostream>
#include "arena.h"

void Arena::battle(Creature &a, Creature &b)
{
    std::cout << a.name << " vs. " << b.name << std::endl;

    if(!Creature::validateBattle(a, b)){
        return;
    }
    
    std::cout << a.name << " vs " << b.name << std::endl;

    int turn = 1;

    while (a.isAlive() && b.isAlive())
    {
        std::cout << "\nTurn " << turn << std::endl;

        std::cout << a.name << " with attack power "<< a.damage << " attacks " << b.name << "!" << std::endl;
        a.attack(b);
        std::cout << b.name << " health is: " << b.health << " HP" << std::endl;

        if (!b.isAlive())
            break;

        std::cout << b.name << " with attack power " << b.damage << " attacks " << a.name << "!" << std::endl;
        b.attack(a);
        std::cout << a.name << " health is: " << a.health << " HP" << std::endl;

        turn++;
    }

    if (a.isAlive())
    {
        std::cout << a.name << " defeats " << b.name << "!" << std::endl;
        std::cout << a.name << " has " << a.health << " HP remaining." << std::endl;
    }
    else
    {
        std::cout << b.name << " defeats " << a.name << "!"<< std::endl;
        std::cout << b.name << " has " << b.health << " HP remaining." << std::endl;
    }
}