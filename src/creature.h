#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <iostream>

// Added many new initialized constants to set parameters for creature stats.
const int MIN_HEALTH = 80;
const int MAX_HEALTH = 120;
const int MIN_DAMAGE = 1;
const int MAX_DAMAGE = 20;
const int MIN_DEFENSE = 0;
const int MAX_DEFENSE = 10;
const int MIN_HEALING = 0;
const int MAX_HEALING = 20;

class Creature
{

// Created private member variables including one static variable for use across all creature class members.
private:
    std::string name;
    int maxHealth;
    int health;
    int damage;
    int defense;
    int healing;
    static int creatureCount;

// Added public member methods methods.
public:
    // Instantiates a Creature constructor method with five parameters.
    Creature(std::string n, int h, int d, int def, int heal);
    
    // Created getter methods to access all private memebr variables.
    std::string getName() const { return name; }
    int getMaxHealth() const { return maxHealth; }
    int getHealth() const { return health; }
    int getDamage() const { return damage; }
    int getDefense() const { return defense; }
    int getHealing() const { return healing; }

    // Added methods for taking damage, healing (a new, special method), and attacking.
    void takeDamage(int amount);
    void heal();
    void attack(Creature &other);
    bool isAlive() const;

    // Returns total creatures created using static private variable.
    static int getCreatureCount() { return creatureCount; }

    // Validation method checking creatures using new methods. Justifies creation of new global constanst variables above.
    static bool validate(const Creature &c);

    // Validates that both creatures have valid stats for battle.
    static bool validateBattle(const Creature &a, const Creature &b);
};

#endif