#include <iostream>
#include "Creature.h"

using namespace std;

Creature::Creature (char name_,int lifespan_, int startCanBorn_, int endCanBorn_, int x_pos_,int y_pos_,int age_) {
	age = age_;
	lifespan = lifespan_;
	startCanBorn = startCanBorn_;
	endCanBorn = endCanBorn_;	
	x_pos = x_pos_;
	y_pos = y_pos_;
	name = name_;
	flag = false;
};

bool Creature::canBorn (void) {
	if (age>=startCanBorn && age<=endCanBorn){
		return true;
	}
	return false;
}

bool Creature::isTooOld (void) {
	return age >= lifespan ? true : false;
}

void Creature::increaseAge (void) {
	age += 1;
}

char Creature::getName (void) const {
	return name;
}

int Creature::getAge (void) const {
	return age;
}

void Creature::setBeenRun (void) {
	flag = true;
}

void Creature::setNotBeenRun (void) {
	flag = false;
}

bool Creature::haveBeenRun (void) {
	return flag;
}

void Creature::daily (void) {	
	if (canBorn()){
		born();
	}
}

