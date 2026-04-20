#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <random>

class Creature
{
public:
    std::string name;
    int health;
    int damage;

    Creature(std::string n, int h, int d)
    {
        name = n;
        health = h;
        damage = d;
    }

    void attack(Creature &other)
    {
         // set a random seed
        static std::mt19937 rng(std::random_device{}());

        // set the damage variation to one quarter of the total. Due to this, bigger hits will have a higher variation, smaller hits will have a lower variation
        int variation = damage / 4;
        // creates an object dist that returns a number within the variation limits for damage. So if damage is 20, variation can be +5 or -5
        std::uniform_int_distribution<int> dist(-variation, variation);

        // set the randomized damage to damage with the variation added
        int damage_randomized = damage + dist(rng);
        other.health -= damage_randomized;

        if (other.health < 0)
        {
            other.health = 0;
        }
    }

    bool isAlive()
    {
        return health > 0;
    }
};

#endif