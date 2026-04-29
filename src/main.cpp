#include "arena.h"
#include "creature.h"
#include "./creatures/sumo_sally.h"
#include "./creatures/giantleech.h"

int main()
{
    Creature c1(make_sumo_sally());
    Creature c2(makeGiantleech());

    // Only addition to main. Prints total number of creatures using new methods implemented in creature.h
    std::cout << "Total creatures created: "
              << Creature::getCreatureCount() << std::endl;

    Arena::battle(c1, c2);

    return 0;
}
