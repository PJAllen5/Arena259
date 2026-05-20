#include "magician.h"

Magician::Magician() : Creature("Magician", 120, 20){}

void Magician::specialMove(Creature& other){
    int magicalHealing = 20;

    this->setHealth(this->getHealth() + magicalHealing);
    std::cout << "The Magician has healed " << magicalHealing << " hp with his magic!\n"
            << "The Magician's health after special move: " << this->getHealth() << std::endl;
}