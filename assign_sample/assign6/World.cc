//World.cc

#include<iostream>
#include<stdlib.h>
#include"Grass.h"
#include"Goat.h"
#include"Creature.h"
#include"RandomNum.h"
#include"World.h"
using namespace std;
World::World(int numPasses,int seed){
    this->numPasses=numPasses;
    this->seed=seed;
    RandomNum rand(seed);
    for(int i=0;i<35;i++){
        for(int j=0;j<20;j++){
            area[i][j]=0;
            field[i][j]=NULL;
        }
    }
    for(int i=0;i<5;i++){
        int tmp=rand.getRandomNum(0,699);
        if(field[tmp%35][tmp%20]==NULL){
            field[tmp%35][tmp%20]=new Goat;
            area[tmp%35][tmp%20]=2;
        }
        else
            i--;
    }
    for(int i=0;i<10;i++){
        int tmp=rand.getRandomNum(0,699);
        if(field[tmp%35][tmp%20]==NULL){
            field[tmp%35][tmp%20]=new Grass;
            area[tmp%35][tmp%20]=1;
        }
        else
            i--;
    }
    out();
}
void World::mainLoop(int displayInterval){
    RandomNum rand(seed);
    for(int a=1;a<numPasses;a++){
        for(int i=0;i<20;i++){
            for(int j=0;j<35;j++){
                if(field[j][i]!=NULL){
                    field[j][i]->setcheck(true);
                }
            }
        }
        for(int i=0;i<20;i++){
            for(int j=0;j<35;j++){
                if(area[j][i]!=0){
                    if(field[j][i]->getcheck()==true){
                        if(area[j][i]==2){
                            if(field[j][i]->getAge()<=1 || field[j][i]->getFood()<=0){
                                field[j][i]=NULL;
                                area[j][i]=0;
                            }
                            else{
                                field[j][i]->setFood(-1);
                                field[j][i]->setAge();
                                field[j][i]->setcheck(false);
                                if(field[j][i]->getAge()<=20 && field[j][i]->getAge()>=15){
                                    int direct=rand.getRandomNum(0,3);
                                    if(direct==0 && j+1<35){
                                        if(area[j+1][i]!=2){
                                            if(area[j+1][i]==1)field[j][i]->setFood(5);
                                            field[j+1][i]=new Goat;
                                            area[j+1][i]=2;
                                        }
                                    }
                                    if(direct==1 && i-1>=0){
                                        if(area[j][i-1]!=2){
                                            if(area[j][i-1]==1)field[j][i]->setFood(5);
                                            field[j][i-1]=new Goat;
                                            area[j][i-1]=2;
                                        }
                                    }
                                    if(direct==2 && j-1>=0){
                                        if(area[j-1][i]!=2){
                                            if(area[j-1][i]==1)field[j][i]->setFood(5);
                                            field[j-1][i]=new Goat;
                                            area[j-1][i]=2;
                                        }
                                    }
                                    if(direct==3 && i+1<20){
                                        if(area[j][i+1]!=2){
                                            if(area[j][i+1]==1)field[j][i]->setFood(5);
                                            field[j][i+1]=new Goat;
                                            area[j][i+1]=2;
                                        }
                                    }
                                }
                                else{
                                    int direct=rand.getRandomNum(0,3);
                                    if(direct==0&&j+1<35){
                                        if(area[j+1][i]!=2){
                                            if(area[j+1][i]==1)field[j][i]->setFood(5);
                                            field[j+1][i]=field[j][i];
                                            field[j][i]=NULL;
                                            area[j+1][i]=2;
                                            area[j][i]=0;
                                        }
                                    }
                                    if(direct==1 && i-1>=0){
                                        if(area[j][i-1]!=2){
                                            if(area[j][i-1]==1)field[j][i]->setFood(5);
                                            field[j][i-1]=field[j][i];
                                            field[j][i]=NULL;
                                            area[j][i-1]=2;
                                            area[j][i]=0;
                                        }
                                    }
                                    if(direct==2 && j-1>=0){
                                        if(area[j-1][i]!=2){
                                            if(area[j-1][i]==1)field[j][i]->setFood(5);
                                            field[j-1][i]=field[j][i];
                                            field[j][i]=NULL;
                                            area[j-1][i]=2;
                                            area[j][i]=0;
                                        }
                                    }
                                    if(direct==3 && i+1<20){
                                        if(area[j][i+1]!=2){
                                            if(area[j][i+1]==1)field[j][i]->setFood(5);
                                            field[j][i+1]=field[j][i];
                                            field[j][i]=NULL;
                                            area[j][i+1]=2;
                                            area[j][i]=0;
                                        }
                                    }
                                }
                            }
                        }
                        else if(area[j][i]==1){
                            if(field[j][i]->getAge()<=1){
                                field[j][i]=NULL;
                                area[j][i]=0;
                            }
                            else{
                                field[j][i]->setFood(-1);
                                field[j][i]->setAge();
                                field[j][i]->setcheck(false);
                                if(field[j][i]->getAge()<=3 && field[j][i]->getAge()>=1){
                                    int direct=rand.getRandomNum(0,3);
                                    if(direct==0 && j+1<35){
                                        if(area[j+1][i]==0){
                                            field[j+1][i]=new Grass;
                                            area[j+1][i]=1;
                                        }
                                    }
                                    if(direct==1 && i-1>=0){
                                        if(area[j][i-1]==0){
                                            field[j][i-1]=new Grass;
                                            area[j][i-1]=1;
                                        }
                                    }
                                    if(direct==2 && j-1>=0){
                                        if(area[j-1][i]==0){
                                            field[j-1][i]=new Grass;
                                            area[j-1][i]=1;
                                        }
                                    }
                                    if(direct==3 && i+1<35){
                                        if(area[j][i+1]==0){
                                            field[j][i+1]=new Grass;
                                            area[j][i+1]=1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(a%displayInterval==0)out();
    }
}
void World::out(){
    cout<<"  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4"<<endl;
    for(int i=0;i<20;i++){
        cout<<i%10;
        for(int j=0;j<35;j++){
            cout<<' ';
            if(area[j][i]==0)cout<<' ';
            else if(area[j][i]==1)cout<<'I';
            else if(area[j][i]==2)cout<<'X';
        }
        cout<<endl;
    }
    cout<<"------------------------------------------------------------------------"<<endl;
}
