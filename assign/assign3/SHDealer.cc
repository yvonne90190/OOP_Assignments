/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */
#include "SHPlayer.h"
#include "SHDealer.h"
#include <algorithm>
#include <iostream> 

using namespace std;

// constructor
SHDealer::SHDealer()
{
	// a dealer with type SHPlayer
	dealerPlayer = new SHPlayer("Dealer");
	deck = new int[24];
	// record how many card had been taken out of deck 
	deckIdx = 0;
}


// destructor
SHDealer::~SHDealer()
{
	delete dealerPlayer;
	delete deck;
}


// distribute a card to the player
int
SHDealer::giveCard()
{
	// take the card from the deck to the player
	return deck[deckIdx++];
}


// give the dealer a card
void
SHDealer::addCard()
{
	// take one card from the deck
	int newCardID = giveCard();
	// add the new card the deal's own hand
	dealerPlayer->addCard(Card(newCardID));
}

// determine who has win the game.
// if both of them have the same pattern,
// the one has more total pips wins the game.
Result
SHDealer::judge(SHPlayer& player)
{
	// first compare the hand pattern 
	if ( dealerPlayer->getHandPattern() < player.getHandPattern() ){
		return WIN;
	}
	// then compare the total pips
	if ( dealerPlayer->getHandPattern() == player.getHandPattern() ){
		if ( dealerPlayer->totalPips() > player.totalPips() ){
			return WIN;
		}
		if ( dealerPlayer->totalPips() == player.totalPips() ){
			return TIE;
		}
	}
	return LOSE;
}

// start a new game(round)
// before starting a new game(round), you should have
// a new deck, and then shuffle it.
// The deck only has pips A, 8, 9, 10, J, Q, K.
void
SHDealer::start()
{
	// initialize the hand
	dealerPlayer->start();
	// shuffle the card
	shuffle();
	// initialize the num of card taken from the deck as 0
	deckIdx = 0;
}


// shuffle the deck of cards
void
SHDealer::shuffle()
{
	// give every card in deck[] a number
	for(int i=0; i<24; ++i){   //A
		deck[i] = i;
		if (i>=4){ // 8, 9, 10, J, Q, K
			deck[i] += 28;
		}
	}
	// shuffle the deck by random swap
	int idx, tmp;
	for(int i=0; i<24; ++i){
		idx = rand() % 24;
		tmp = deck[i];
		deck[i] = deck[idx];
		deck[idx] = tmp;
	}
}


// open the dealer's first card
void
SHDealer::openFirstCard()
{
	dealerPlayer->openFirstCard();
}


// show the dealer's hand to the screen
void
SHDealer::showCards() const
{
	dealerPlayer->showCards();	
}
