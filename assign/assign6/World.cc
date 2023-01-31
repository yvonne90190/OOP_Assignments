#include <iostream>
#include "RandomNum.h"
#include "Grass.h"
#include "Goat.h"
#include "Creature.h"
#include <stdlib.h>

using namespace std;

World::World (int maxRound_,int seed_) :random(seed_){
	maxRound = maxRound_;
	seed = seed_;
	for (int i=0; i<20; ++i) {
		for (int j=0; j<35; ++j) {
			farm[i][j] = NULL;
		}
	} 
	int x, y;
	for (int i=0; i<5;) {
		x = random.getRandomNum(0,34);
		y = random.getRandomNum(0,19);
		if (isNull(y,x)){
			bornGoat(y,x);
			i++;
		}
	} 
	for (int i=0;i<10;) {
		x = random.getRandomNum(0,34);
		y = random.getRandomNum(0,19);
		if (isNull(y,x)){
			bornGrass(y,x);
			i++;
		}
	} 
}

World::~World () {

}

void World::mainLoop (int displayInterval) {
	int day = 1;
	showResult();  // first round, show first
	while (day<maxRound) {
		++day;
		daily();   // other round, update -> show
		if ((day-1)%displayInterval == 0) {
//			cout << "day " << day << endl; 
			showResult();
		}
	}
}

void World::initilize (void) {
	for (int i = 0;i<20;++i) {
		for (int j = 0;j<35;++j) {
			if (farm[i][j] != NULL) {
				farm[i][j]->setNotBeenRun();
			}
		}
	}
}

void World::daily (void) {
	initilize();
	for (int i=0; i<20; ++i) {
		for (int j=0; j<35; ++j) {
			if (farm[i][j] != NULL && !farm[i][j]->haveBeenRun()) {
//				cout << i << " " << j << endl;
				farm[i][j]->daily();
	//			cout << "after daily" << endl;
			}
		}
	} 
}

void World::bornGrass (int y,int x) {
	farm[y][x] = new Grass((*this),x,y,0,6,3,5,'I');
	farm[y][x]->setBeenRun();
}

void World::bornGoat (int y,int x) {
	farm[y][x] = new Goat(x,y,(*this),0,70,50,55,'X');
	farm[y][x]->setBeenRun();
}

void World::moveGoat (int y,int x,int direction) {
	int orgin_x = x;
	int orgin_y = y;
	x += dir_x[direction];
	y += dir_y[direction];	
	farm[y][x] = farm[orgin_y][orgin_x];
	farm[y][x]->setBeenRun(); 
	farm[orgin_y][orgin_x] = NULL; 
}

char World::getName (int y, int x) {
	return farm[y][x]->getName();
}

void World::setClear(int y, int x) {
	farm[y][x]->setNotBeenRun();
	delete farm[y][x];
	farm[y][x] = NULL;
}

bool World::outOfBound (int y,int x) {
	if (x<0 || x>=35 || y<0 || y>=20) {
		return true;
	} 
	return false;
}

bool World::isNull (int y,int x) {
	if (farm[y][x] == NULL) {
		return true;
	}
   	return false;	
}

void World::showResult (void) {
	cout << "  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4" << endl;
	for (int i = 0;i<20;++i) {
		cout << i%10 ;
		for (int j = 0;j<35;++j) {
			if (farm[i][j] == NULL) {
				cout << "  " ;
			} else {
				cout << " " ;
				cout << farm[i][j]->getName() ;
			}
		} cout << endl ;
	} cout << "------------------------------------------------------------------------\n" ;
}
