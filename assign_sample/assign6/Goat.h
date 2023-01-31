//Goat.h

#ifndef _GOAT_H_
#define _GOAT_H_
#include"Creature.h"
class Goat:public Creature{
    public:
        Goat();
//        void born();
//        void move();
        int getAge();
        int getFood();
        bool getcheck();
        void setAge();
        void setFood(int change);
        void setcheck(bool input);
    private:
        bool check;
        int age;
        int food;
};
#endif

