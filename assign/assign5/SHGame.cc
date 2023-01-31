/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */

#include "SHGame.h"
#include "SHPlayer.h"
#include "SHDealer.h"

#include <iostream>
using namespace std;

// only constructor
// Must be given a valid (initialized) game player and dealer
// Menu is constructed internally to provide basic text interface
// We must use an initialization list here.
SHGame::SHGame(SHPlayer& shp, SHDealer& shd)
    : menu(sizeof(menuItems)/sizeof(char*), menuItems), player(shp), dealer(shd)
{
    over = true;
    playerCredit = initCredit;
    dealerCredit = initCredit;
	restart();
}


// one run of the game
// take and process a user action
// show current hands for both players at the end of a run.
bool
SHGame::oneRun()
{
    int choice = 0;   
	static bool isFirst = true;
	if(isFirst){
		player.showCards();
		dealer.showCards();
		isFirst = false;
	}
	// main menu processing
    menu.print();
    choice = menu.getAnswer();

    switch( choice ) {
        case ONE_MORE:
            moreCard();
            break;
            
        case GIVE_UP:
            giveUp();
            break;
            
        case RESTART:
            restart();
            break;
            
        case QUIT:
            return false;

        default:
            break;
    }

    // print the cards at the end of each process loop
    player.showCards();

    if( over )
        dealer.openFirstCard();
    dealer.showCards();

    return true;
}


// give the player and dealer one more card
// check if we can do that first.
// and judge who has win the round if the player have 5 cards
void
SHGame::moreCard()
{
    // check if it's legal to do this
    if( over ) {
        cout << "GAME OVER!" << endl;
        return;
    } 

    if( player.getNumCards() <= 0 ) {
        // the game may not have started yet
        cout << "You need to start a new game first." << endl;
    }
    else if( player.getNumCards() < 5 ) {
        bet++;
        player.addCard(dealer.giveCard());
        dealer.addCard();
    }

    if( player.getNumCards() == 5 ) {
        switch( dealer.judge(player) ) {
            case WIN:
                playerCredit += bet;
                dealerCredit -= bet;
                cout << "You win. Good job.";
                break;
                
            case LOSE:
                playerCredit -= bet;
                dealerCredit += bet;
                cout << "I win. Try again.";
                break;
                
            case TIE: // no tie in this game
            default:
                break;
        }
        cout << "(You have " << playerCredit << " points, ";
        cout << "I Have " << dealerCredit << " points.)" << endl;

        over = true;
    }
}


// give up this round,
// and you'll lose your credit
// the bet is equivalent to the number of card you keep
void
SHGame::giveUp()
{
    // check if it's legal to do this
    if( over ) {
        cout << "GAME OVER!" << endl;
        return;
    }

    // the dealer wins!
    playerCredit -= bet;
    dealerCredit += bet;

    cout << "I win. Try again.";
    cout << "(You have " << playerCredit << " points, ";
    cout << "I Have " << dealerCredit << " points.)" << endl;

    over = true;
}


// restart the game by giving each player two new cards
// need to check if any one broke (bankrupt).
void
SHGame::restart()
{
    if( !over ) {
        cout << "Game is not over yet. Choose 'give up' to end a game" << endl;
        return;
    }

    // restart the game if both sides have positive credits
    if( (playerCredit <= 0) || (dealerCredit <= 0 ) ) {
        cout << "Sorry. Game over. No loan here." << endl;
        return;
    }

    // since the dealer needs to have a new deck, 
    // the start() function for te dealer class needs to be called
    // before the player class
    dealer.start();
    player.start();

    // first run
    player.addCard(dealer.giveCard());
    dealer.addCard();
    // second run
    player.addCard(dealer.giveCard());
    dealer.addCard();
    // view the first card
    player.openFirstCard();
    bet = betCredit * 2; 
    over = false;
}
