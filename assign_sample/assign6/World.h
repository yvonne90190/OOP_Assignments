//World.h

#ifndef _WORLD_H
#define _WORLD_H
#include"Creature.h"
//class Creature;
class World{
    private:
        Creature *field[35][20];
        long area[35][20];
        int numPasses;
        int displayInterval;
        int seed;
    public:
        World(int numPasses,int seed);
        void mainLoop(int displayInterval);
        void out();
};
#endif
