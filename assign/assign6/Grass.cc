#include <iostream>
#include "Creature.h"
#include "World.h"
#include "RandomNum.h"
#include "Grass.h"
#include <stdlib.h>

using namespace std;

Grass::Grass (World &infate,int x,int y,int age, int lifespan, int startCanBorn, int endCanBorn, char id)
:Creature(id,lifespan,startCanBorn,endCanBorn,x,y,age),fate(infate) {
}

void Grass::born (void) {
	int direction = fate.random.getRandomNum(0,3);
//	cout << "dir = " << direction << " ";
	int child_x = x_pos + dir_x[direction];
	int child_y = y_pos + dir_y[direction];
	if (!fate.outOfBound(child_y,child_x) && fate.isNull(child_y,child_x)) {
		fate.bornGrass(child_y,child_x);
	}
}

void Grass::daily (void) {
	increaseAge();
//	cout << "Grass (" << x_pos << "," << y_pos << ") age = " << getAge();
	if (isDead()){
//		cout <<  "Die";	
		fate.setClear(y_pos, x_pos);
	} 
	else if (canBorn()){
		born();
	}
//	cout << endl;
}

bool Grass::isDead (void) {
	return isTooOld();
}
