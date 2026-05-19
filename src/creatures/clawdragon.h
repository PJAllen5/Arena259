#ifndef CLAWDRAGON_H
#define CLAWDRAGON_H
#include "../creature.h"

class Clawdragon : public Creature{
public:
    Clawdragon();

    void specialMove(Creature& other) override;
};


#endif