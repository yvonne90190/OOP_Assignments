#include <iostream>
#include "Creature.h"
#include "World.h"
#include "RandomNum.h"
#include "Goat.h"
#include <stdlib.h>
#include <time.h>

using namespace std;


Goat::Goat (int x, int y, World &infate, int age, int lifespan, int startCanBorn, int endCanBorn, char name)
	:Creature(name, lifespan, startCanBorn, endCanBorn, x, y, age), fate(infate) {
		foodpoint = 20;
}

void Goat::born (void) {
	int direction = fate.random.getRandomNum(0,3);
	int new_x = x_pos + dir_x[direction];
	int new_y = y_pos + dir_y[direction];	
	if (!fate.outOfBound(new_y, new_x))  {		
		if (!fate.isNull(new_y, new_x) && fate.getName(new_y, new_x) == 'I') {
			eat();
			//cout << "  eat : <" << new_x << "," << new_y << ">" << endl;
			fate.setClear(new_y, new_x);
			fate.bornGoat(new_y, new_x);
		}
		else if (fate.isNull(new_y, new_x)) {
			fate.bornGoat(new_y, new_x);	
		}
	}
}

void Goat::daily (void) {
	increaseAge();
	consume();	
	if (isDead()){
	//	cout <<  "  Die";	
		fate.setClear(y_pos, x_pos);
	}
	else { 
	//cout <<  "Goat (" << x_pos << "," << y_pos << ")  Point = " << foodpoint << "Age = "  << getAge();	
		if (canBorn()){
			born();
		}
		else {
			moving();
		}
	}
	//cout << endl;
}

void Goat::moving (void) {  //fail
	int direction = fate.random.getRandomNum(0,3);
	int new_x = x_pos + dir_x[direction];
	int new_y = y_pos + dir_y[direction];
	if (!fate.outOfBound(new_y, new_x)) {		
		if (!fate.isNull(new_y, new_x) && fate.getName(new_y, new_x) == 'I') {
			eat();
			fate.setClear(new_y, new_x);
		}	
		fate.moveGoat(y_pos, x_pos, direction);
		x_pos = new_x;
		y_pos = new_y;	
	}
}

bool Goat::isDead (void) {
	if (isTooOld() || isStarving()){
		return true;
	}
	return false;
}

bool Goat::isStarving (void) const {
	return foodpoint <= 0 ? true : false;
}

void Goat::eat (void) {
	foodpoint += 5;
}

void Goat::consume (void) {
	foodpoint -= 1;
}

