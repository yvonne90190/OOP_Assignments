#pragma once

#include <iostream>

using namespace std;

class Creature {
	public:
		Creature(char name_, int lifespan_, int startCanBorn_, int endCanBorn_, 
				 int x_pos_, int y_pos_, int age_=0);
		virtual ~Creature(){};
		virtual void daily(void);
		char getName(void) const ;
		int getAge(void) const ;
		void setBeenRun(void);
		void setNotBeenRun(void);
		bool haveBeenRun(void);
	protected:
		void increaseAge(void); 
		virtual void born(void)=0;
		virtual bool isDead(void)=0;
		bool isTooOld(void);
		bool canBorn(void);
		int x_pos;
		int y_pos;
	private:
		int age;
		int lifespan;
		int startCanBorn;
		int endCanBorn;
		char name;
		bool flag;
};

