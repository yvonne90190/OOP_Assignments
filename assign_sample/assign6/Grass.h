//Grass.h

#ifndef _GRASS_H_
#define _GRASS_H_
#include"Creature.h"
class Grass : public Creature{
    public:
        Grass();
//        void born();
        void setAge();
        int getAge();
        void setcheck(bool input);
        bool getcheck();
    private:
        int age;
        bool check;
};
#endif


