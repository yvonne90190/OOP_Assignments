#pragma once

#include <iostream>
#include "World.h"

using namespace std;

class Creature;

class Grass : public Creature {
	public:
		Grass(World &infate,int x,int y,int life=0,int lifespan=6,int startCanBorn=3,int endCanBorn=5,char id='I');
		virtual ~Grass(){};
		virtual bool isDead(void);
		virtual void daily(void);
	private:
		virtual void born(void);
		World &fate;
};
