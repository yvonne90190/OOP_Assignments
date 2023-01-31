#pragma once

#include <iostream>
#include "Creature.h"
#include "RandomNum.h"

using namespace std;

const int dir_x[4] = {0, 0, -1, 1};
const int dir_y[4] = {-1, 1, 0, 0};

class World {
	public:
		World(int maxRound_,int seed_);
		//~World(){}; error
		~World();
		void mainLoop(int time);
		bool outOfBound(int y,int x);
		bool isNull(int y,int x);
		void setClear(int y, int x);
		char getName(int y, int x);
		void bornGrass(int y,int x);
		void bornGoat(int y,int x);
		void moveGoat(int y,int x,int direction);
		RandomNum random;
	private:
		void daily(void);
		void showResult(void);
		void initilize(void);
		Creature *farm[20][35];
		int maxRound;
		int seed;
};

