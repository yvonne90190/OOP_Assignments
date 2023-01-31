//Creature.h

#ifndef _CREATURE_H
#define _CREATURE_H
class Creature{
    public:
        virtual int getAge()=0;
        virtual int getFood();
        virtual bool getcheck()=0;
        virtual void setAge()=0;
        virtual void setFood(int change);
        virtual void setcheck(bool input)=0;
    private:
};
#endif

