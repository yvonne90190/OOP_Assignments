#pragma once

#include <iostream>
#include "Creature.h"
#include "World.h"

using namespace std;

class Goat: public Creature {
	public:
		Goat(int x,int y,World &infate,int age=0,int lifespan=70,int startCanBorn=50,int endCanBorn=55, char id='X');
		virtual ~Goat(){};	
		virtual bool isDead(void);
	    virtual void daily(void);
	private:
		virtual void born(void);
		void moving(void);
		bool isStarving(void) const ;
		void eat(void);
		void consume(void);
		World &fate;
		int foodpoint;
};

