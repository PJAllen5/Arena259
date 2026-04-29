#include "creature.h"

// Initialize static variable
int Creature::creatureCount = 0;

// Constructor definition
Creature::Creature(std::string n, int h, int d, int def, int heal)
    : name(n), maxHealth(h), health(h), damage(d), defense(def), healing(heal)
{
    creatureCount++;
}

// Takes damage considering creature's defense.
void Creature::takeDamage(int amount)
{
    int actualDamage = amount - defense; // Calculates actual damge as a subtraction of defense from orther damage.
    if (actualDamage > 0) {
        health -= actualDamage;
        if (health < 0) {
            health = 0;
        }
    }
}

// Gives creatures a chance to heal themselves.
void Creature::heal()
{
    health += healing;
    if (health > maxHealth) {
        health = maxHealth;
    }
}

// Attack method that directs damage against another creature.
void Creature::attack(Creature &other)
{
    other.takeDamage(damage); // Directs attacks against opponents in areana.
}

// Checks if creature is alive.
bool Creature::isAlive() const
{
    return health > 0;
}

// Validation method checking creatures using new methods.
bool Creature::validate(const Creature &c)
{
    if(c.health < MIN_HEALTH || c.health > MAX_HEALTH){
        std::cerr << "Error: " << c.getName() << " has invalid health. Health must be between " << MIN_HEALTH << " and " << MAX_HEALTH << std::endl;
        return false;
    }
    if(c.damage < MIN_DAMAGE || c.damage > MAX_DAMAGE){
        std::cerr << "Error: " << c.getName() << " has invalid damage. Damage must be between " << MIN_DAMAGE << " and " << MAX_DAMAGE << std::endl;
        return false;
    }
    if(c.defense < MIN_DEFENSE || c.defense > MAX_DEFENSE){
        std::cerr << "Error: " << c.getName() << " has invalid defense. Defense must be between " << MIN_DEFENSE << " and " << MAX_DEFENSE << std::endl;
        return false;
    }
    if(c.healing < MIN_HEALING || c.healing > MAX_HEALING){
        std::cerr << "Error: " << c.getName() << " has invalid healing. Healing must be between " << MIN_HEALING << " and " << MAX_HEALING << std::endl;
        return false;
    }
    return true;
}

// Validates that both creatures have valid stats for battle.
bool Creature::validateBattle(const Creature &a, const Creature &b)
{
    if(!validate(a) || !validate(b)){
        std::cerr << "The Battle cannot take place as there are invalid stats" << std::endl;
        return false;
    }
    return true;
}
