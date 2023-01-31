/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */

#ifndef _SHGAME_H_
#define _SHGAME_H_
#include "SHDealer.h"
#include "ConsoleMenu.h"
// forward declaration
class SHPlayer;
class SHDealer;

// menu for actions that are used in the show hand game
const char* const menuItems[] = {"One more card",
                                 "give up",
                                 "restart",
                                 "quit"
                                };

enum Option {ONE_MORE = 1, GIVE_UP, RESTART, QUIT};

// the show hand game
class SHGame {

    public:

        /**
         * constructor
         * require an initialized player and a dealer
         */
        SHGame(SHPlayer& shp, SHDealer& shd);

        /**
         * one run of the game: return FALSE if quit
         * one run means taking and processing a user action
         */
        bool oneRun();
		void start();
    private:
		// routines to handles actions
		// give the each player one more card
        void moreCard();
        // give up this round
        void giveUp();
        // restart the game over
        void restart();

	private:
        
        // menu item strings
        ConsoleMenu menu;

        // references to a player and a dealer
        SHPlayer& player;
        SHDealer& dealer;

        // credits
        static const int initCredit = 20;
        static const int betCredit = 1;

        // TODO: more data and functions to add here ...
		bool gameOver;
		int playerCredit;
		int dealerCredit;
		void implementJudgeResult(Result result); 
};


#endif // _SHGAME_H_
