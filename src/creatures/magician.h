#ifndef MAGICIAN_H
#define MAGICIAN_H

#include "../creature.h"

class Magician : public Creature{
    public:
        Magician();

        void specialMove(Creature& other) override;
};



 #endif