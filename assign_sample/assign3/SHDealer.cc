/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */


#include "SHPlayer.h"
#include "SHDealer.h"
#include <cassert>
#include <algorithm>
#include <iostream>

// constructor
SHDealer::SHDealer() : dealer("Dealer")
{
    nTotalCards = 6 * 4;       // (9, 10, J, Q, K, A) * 4
    cardId = new int[nTotalCards];
}


// destructor
SHDealer::~SHDealer()
{
    delete [] cardId;
}


// distribute a card to the player
int
SHDealer::giveCard()
{
    assert( cardDealt < nTotalCards );
    return cardId[cardDealt++];
}


// give the dealer a card
void
SHDealer::addCard()
{
    dealer.addCard(giveCard());
}


// determind who has win the game.
// if both of them have the same pattern,
// the one has more total pips wins the game.
Result
SHDealer::judge(SHPlayer& player)
{
	// std::cout << "dealer pattern: " << HandTypeName[dealer.getHandPattern()] << std::endl;
    // std::cout << "player pattern: " << HandTypeName[player.getHandPattern()] << std::endl;
	// std::cout << "dealer pips: " << dealer.totalPips() << std::endl;
	// std::cout << "player pips: " << player.totalPips() << std::endl;
    if( (int)player.getHandPattern() < (int)dealer.getHandPattern() )
        return WIN;
    else if( (int)player.getHandPattern() > (int)dealer.getHandPattern() )
        return LOSE;

    if( player.totalPips() > dealer.totalPips() )
        return WIN;
    else if( player.totalPips() < dealer.totalPips() )
        return LOSE;

    return TIE;
}


// start a new game(round)
// before starting a new game(round), you should have
// a new deck, and then shuffle it.
// The deck only has pips A, 8, 9, 10, J, Q, K.
void
SHDealer::start()
{
    dealer.start();

    for( int i = 0; i < 4; i++ )                // A
        cardId[i] = i;
    for( int i = 4, j = 32; j < 52; i++, j++ )  // 8, 9, 10, J, Q, K
        cardId[i] = j;

	cardDealt = 0;
    shuffle();
}


// shuffle the deck of cards
void
SHDealer::shuffle()
{
    for( int i = 0; i < nTotalCards; i++ )
        std::swap(cardId[i], cardId[rand() % nTotalCards]);
}


// open the dealer's first card
void
SHDealer::openFirstCard()
{
    dealer.openFirstCard();
}


// show the dealer's hand to the screen
void
SHDealer::showCards() const
{
    dealer.showCards();
}
