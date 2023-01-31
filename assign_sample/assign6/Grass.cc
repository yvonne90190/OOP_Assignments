//Grass.cc

#include<iostream>
#include"Grass.h"
#include"Creature.h"
using namespace std;
Grass::Grass(){
    age=6;
    check=false;
}
/*
void Grass::born(){

}
*/
void Grass::setcheck(bool input){
    check=input;
}
bool Grass::getcheck(){
    return check;
}
void Grass::setAge(){
    age--;
}
int Grass::getAge(){
    return age;
}
