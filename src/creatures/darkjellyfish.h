#ifndef DARKJELLYFISH_H
#define DARKJELLYFISH_H

#include "../creature.h"

class DarkJellyfish:public Creature {
	public:
		DarkJellyfish();

		void specialMove(Creature& other) override;
};

#endif
