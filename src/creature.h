#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <iostream>

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

        other.health -= damage;
        if (other.health < 0)
        {
            other.health = 0;
        }
    }

    bool isAlive()
    {
        return health > 0;
    }

    static bool validate(Creature &c){
        if(c.health <= 0 || c.health > 120){
            std::cerr << "Error: " << c.name << " has invalid health. Health must be > 0 or <= 120" << std::endl;
            return false;
        }
        if(c.damage <= 0 || c.damage > 20){
            std::cerr << "Error: " << c.name << " has invalid damage. Damage must be > 0 or <= 20" << std::endl;
            return false;
        }
        return true;
    }

    /*
    If Creature a or b does not have the valid stats for health or damage
    It will output an error message and abort
    */
    static bool validateBattle(Creature &a, Creature &b){
        if(!validate(a) || !validate(b)){
            std::cerr << "The Battle cannot take place as there are invalid stats" << std::endl;
            return false;
        }
        return true;
    }
};

#endif