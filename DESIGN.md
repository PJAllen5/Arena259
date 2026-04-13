# Creature Base Class - 01
```C++
// An incomplete example of what a base creature class might look like.

#include <string>

class Creature {
    public:
        void printStats();  // prints a creatures stats to cout
        Creature();        
        Creature(int hp, int attack, int defense, int special)  // Constructor with stats allocation
            : hp_(hp)
            , attack_(attack)
            , defense_(defense)
            , special_(special) 
            {};
             void takeDamage(int damage);   // takeDamage implemented in the base class to enforce consistency across the derived classes.
        ~Creature();
    protected:
        virtual void attackPrimary(Creature& target) = 0;
        virtual void useSpecialAbility(Creature& target) = 0;
    private:
        int point_pool_ = 30;   // Use of a fixed "point pool" used for stat allocation and validation. 
        int hp_;
        int attack_;
        int defense_;
        int special_;
        bool checkStats();
};


// simple damage calculation that accounts for defenses and uses abs() to prevent operator shennanigans
void Creature::takeDamage(int damage) {
    hp_ -= std::abs(damage) - (defense_ % 2);  
}

// Checks stats allocation for compliance with point pool restrictions.
// returns false if stats sum(stats) != point pool total
bool Creature::checkStats() {
    return hp_ + attack_ + defense_ + special_ == point_pool_; 
}
```