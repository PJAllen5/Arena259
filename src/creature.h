// An incomplete example of what a base creature class might look like.

#include <string>

class Creature {
    public:
        void printStats();
        Creature();
        Creature(int hp, int attack, int defense, int special)
            : hp_(hp)
            , attack_(attack)
            , defense_(defense)
            , special_(special) 
            {};
             void takeDamage(int damage);
        ~Creature();
    protected:
        virtual void attackPrimary(Creature& target) = 0;
        virtual void useSpecialAbility(Creature& target) = 0;
    private:
        int point_pool_ = 30;
        int hp_;
        int attack_;
        int defense_;
        int special_;
        bool checkStats();
};

void Creature::takeDamage(int damage) {
    hp_ -= std::abs(damage) - (defense_ % 2);
}

bool Creature::checkStats() {
    return hp_ + attack_ + defense_ + special_ == point_pool_;
}
