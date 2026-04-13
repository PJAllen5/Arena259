#include "arena.h"
#include "creature.h"

int main()
{
    Creature c1("Alpha", 100, 15);
    Creature c2("Beta", 100, 12);

    Arena::battle(c1, c2);

    return 0;
}