#include <cassert>
#include <iostream>
#include <string>
#include "../src/creature.h"
#include "../src/creatures/viper.h"
#include "../src/creatures/boogeyman.h" 
#include "../src/creatures/clawdragon.h"
#include "../src/creatures/giantleech.h"
#include "../src/creatures/segoblin.h"
#include "../src/creatures/sumo_sally.h"

//Main testing function
void test_max_damage(const Creature& c) {
    if (!(2 * c.damage < 60)) {
        std::cout << "This creature does too much damage too quickly and must be rebalanced!" << std::endl;
        assert(false);
    }
}

//Shows what creatures are available for testing manual inclusion makes it less fancy of each monster though..
int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <creature_name>" << std::endl;
        std::cout << "Available creatures: viper, clawdragon, giantleech, segoblin, sumo_sally" << std::endl;
        return 1;
    }


    //Check to see if user has inputed a valid creature name. Tells person if they have not then exits.
    //Room for misspelling error, but user has to handle getting file name right.
    std::string creature_name = argv[1];
    Creature c("", 0, 0); // initialization of Creature object c

    //assigns c to creature class instantion.
    if (creature_name == "viper") {
        c = makeViper();
    } else if (creature_name == "clawdragon") {
        c = makeClawdragon();
    } else if (creature_name == "giantleech") {
        c = makeGiantleech();
    } else if (creature_name == "segoblin") {
        c = makeSEGoblin();
    } else if (creature_name == "sumo_sally") {
        c = make_sumo_sally();
    } else {
        std::cout << "Unknown creature: " << creature_name << std::endl;
        return 1;
    }

    //Runs the test proper and prints out the "you did less than 60 damage in 2 turns" then finishes.
    //If it's more it'll crash
    test_max_damage(c);
    std::cout << "Test passed for " << c.name << ": Max damage in two turns is less than 60." << std::endl;
    return 0;
}