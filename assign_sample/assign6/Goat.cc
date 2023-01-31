//Goat.cc

#include<iostream>
#include"Creature.h"
#include"Goat.h"
using namespace std;
Goat::Goat(){
    age=70;
    food=20;
    check=false;
}
/*
void Goat::born(){

}

void Goat::move(){
}
*/
int Goat::getAge(){
    return age;
}
int Goat::getFood(){
    return food;
}
bool Goat::getcheck(){
    return check;
}
void Goat::setAge(){
    age--;
}
void Goat::setFood(int change){
    food=food+change;
}
void Goat::setcheck(bool input){
    check=input;
}
