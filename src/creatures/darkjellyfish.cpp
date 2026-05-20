

#include "darkjellyfish.h"
#include <iostream>


// default constructor
DarkJellyfish::DarkJellyfish() : Creature("Dark Jellyfish", 80, 20) {} // squishy but high damage


void DarkJellyfish::specialMove(Creature &other) {
	int darkDamage = 30; // later if we add damage types this could be more effective
	
	std::cout << getName() << " uses a dark lightning attack on " << other.getName() << " for "
	<< darkDamage << " damage!" << std::endl; // print out a message describing the damage

	other.takeDamage(darkDamage); // force the enemy to take dark damage
}
