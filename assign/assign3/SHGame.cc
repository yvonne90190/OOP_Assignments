/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */
#include <iostream>
#include "SHGame.h"
#include "SHPlayer.h"
#include "SHDealer.h"
#include "ConsoleMenu.h"

using namespace std;
// only constructor
// Must be given a valid (initialized) game player and dealer
// Menu is constructed internally to provide basic text interface
// We must use an initialization list here.
SHGame::SHGame(SHPlayer& shp, SHDealer& shd)
    : menu(sizeof(menuItems)/sizeof(char*), menuItems), player(shp), dealer(shd)
{
	gameOver = false;
	// player and dealer have initCredit at the beginning
	playerCredit = initCredit;
	dealerCredit = initCredit;
}

// one run of the game
// take and process a user action
// show current hands for both players at the end of a run.
bool
SHGame::oneRun()
{	
	// show menu, get the action
	menu.print();
	int action = menu.getAnswer();	
	// do action
	switch(action){
		case 1:
			moreCard();
			break;
		case 2:
			giveUp();
			break;
		case 3:
			restart();
			break;
		case 4:
			return false;
	}
	// show current cards
	if(gameOver){
		dealer.openFirstCard();
	}
	player.showCards();
	dealer.showCards();
	return true;
}

// give the player and dealer one more card
// check if we can do that first.
// and judge who has win the round if the player have 5 cards
void
SHGame::moreCard()
{	
	// if game is over -> print "GAME OVER!"
	if(gameOver){
		cout << "GAME OVER!" << endl;	
	}
	// else -> add an additional card
	else{
		int newCardID = dealer.giveCard();
		player.addCard(Card(newCardID));
		dealer.addCard();	
		// if reach 5 cards	
		if(player.getNumCards() == 5){
			// mark the game is over
			gameOver = true;
			// judge the result
			Result result = dealer.judge(player);
			// print the result, and calculate the new credit
			implementJudgeResult(result);	 
		}
	}
}


// give up this round,
// and you'll lose your credit
// the bet is equivalent to the number of card you keep
void
SHGame::giveUp()
{
	// if the game is not over yet -> can give up
	if(!gameOver){
		// give up -> mark the game is over
		gameOver = true;
		// give up means dealer win
		Result result = WIN;   
		// print the result, and calculate the new credit
		implementJudgeResult(result);
	}	
	// the game is already over -> can not give up
	else{
		cout << "GAME OVER!" << endl;
	}
}

void
SHGame::start()
{
	// initialize both player and dealer
	player.start();
	dealer.start();
	// give both 2 new cards;
	for(int i=0 ;i<2 ; ++i){
		moreCard();
	}
	// always shows player's first card
	player.openFirstCard();	
	// show cards
	player.showCards();
	dealer.showCards();
}

// restart the game by giving each player two new cards
// need to check if any one broke (bankrupt).
void
SHGame::restart()
{
	// if game is not over yet -> can not restart
	if(!gameOver){
		cout << "Game is not over yet. Choose 'give up' to end the game" << endl;
	}
	// if each one bankrupt -> can not restart
	else if(playerCredit <= 0 || dealerCredit <=0){
		cout << "Sorry. Game over. No loan here." << endl;
	}
	// restart
	else{
		// a new round, game not over
		gameOver = false;
		// initialize both player and dealer
		player.start();
		dealer.start();
		// always show play's first card
		player.openFirstCard();
		// add 2 new cards;
		for(int i=0 ;i<2 ; ++i){
			moreCard();
		}	
	}
}

void 
SHGame::implementJudgeResult(Result result)
{
	// change the credit according to the judge result
	// print the result
	switch(result){
		case TIE:
			break;
		case LOSE:   // dealer lose
			playerCredit += player.getNumCards();
			dealerCredit -= player.getNumCards();
			cout << "You win. Good job.";
			break; 
		case WIN:    // dealeer win
			dealerCredit += player.getNumCards();
			playerCredit -= player.getNumCards();
			cout << "I win. Try again.";
			break;
	}
	cout << "(You have " << playerCredit << " points, I Have " << dealerCredit << " points.)" << endl;
}

