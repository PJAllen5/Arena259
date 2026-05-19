// Dennis & Tristan

#include "clawdragon.h"
#include "../rng.h"
#include <iostream>


Clawdragon::Clawdragon()
    : Creature("Clawdragon", 101, 18){
    }

void Clawdragon::specialMove(Creature& other){
    int slashDamage = RNG::randomValue(10, 25);
    std::cout << getName() << " slashes " << other.getName() << " with claws for "
              << slashDamage << " damage" << std::endl;
    other.takeDamage(slashDamage);
    incDamageDealt(slashDamage);
}