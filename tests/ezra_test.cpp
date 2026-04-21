
#include <cassert>
#include <iostream>
#include "../src/creature.h"


// Factore function for a basic creature
Creature TestCreature1() {
	return Creature("Test", 20, 10); // create a creature
					  // named "Test" with 20 health and 10 damage
}

// Testing out reading a creatures variables
void CreatureVariablesTest() {
	// create our test creatures
	Creature Creature1 = TestCreature1();
	Creature Creature2("Alpha 21xy&", 1, 1); // try out a weird name
	Creature Creature3("Dude", -1, -1); // this is implementation dependant
					    // but let's assume we want this to be set to 0
		
	assert(Creature1.name == "Test"); // check variables on a normally constructed creature
	assert(Creature1.health == 20);
	assert(Creature1.damage == 10);

	assert(Creature2.name == "Alpha 21xy&"); // testing weird names
	assert(Creature2.health == 1); 
	assert(Creature2.damage == 1);

	assert(Creature3.health == 0); // require negative health in constructor to set it 0
	assert(Creature3.damage == 0);
}

// Test out attacking creatures
void CreatureAttackTest() {
	// create two test creatures
	Creature Creature1 = TestCreature1();
	Creature Creature2 = TestCreature1();

	assert(Creature2.health == 20); 
	Creature1.attack(Creature2); // deals 10 damage to creature 2

	assert(Creature2.health == 10); // 20 - 10 = 10
	assert(Creature2.isAlive()); // health is still greater than 0
	assert(Creature1.health == 20); // make sure creature 1's health doesn't change
	
	Creature2.attack(Creature1); // now Creature #2 will attack #1
	assert(Creature1.health == 10);
	assert(Creature1.isAlive());

	Creature1.attack(Creature2); // finish off Creature #2
	assert(Creature2.health == 0);
	assert(!Creature2.isAlive());
	Creature1.attack(Creature2);
	assert(Creature2.health == 0); // no negative hp allowed
}


int main() {
	CreatureVariablesTest();
	CreatureAttackTest();
	std::cout << "All tests passed" << std::endl;
}
