#include "creature.h"

class Ogre : public Creature {
    public:
        Ogre(): Creature(hp_, attack_, defense_, special_) {};
        void attackPrimary(Creature& target) override;
        void useSpecialAbility(Creature& target) override;
    private:
        int hp_ = 10;
        int attack_ = 10;
        int defense_ = 8;
        int special_ = 2;
        std::string name_;
        std::string primaryAttackName_;
        std::string secondaryAttackName_;
        std::string specialAbilityName_;
};

void Ogre::attackPrimary(Creature& target) {
    target.takeDamage(attack_);
}