#include "arena.h"
#include "creature.h"
#include "./creatures/viper.h"
#include "./creatures/giantleech.h"
#include <cstdlib> // for std::rand and std::srand
#include <ctime>

int main()
{
    std::srand(std::time(0)); // seed random number generator
    Creature c1(makeViper());
    Creature c2(makeGiantleech());

    Arena::battle(c1, c2);

    return 0;
}