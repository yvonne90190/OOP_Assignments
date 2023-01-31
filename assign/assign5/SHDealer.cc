/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */


#include "SHPlayer.h"
#include "SHDealer.h"

#include <cassert>
#include <algorithm>


// constructor
SHDealer::SHDealer() : SHPlayer("Dealer")
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
	SHPlayer::addCard(giveCard());
}


// determind who has win the game.
// if both of them have the same pattern,
// the one has more total pips wins the game.
Result
SHDealer::judge(SHPlayer& player)
{
    if( (int)player.getHandPattern() < (int)getHandPattern() )
        return WIN;
    else if( (int)player.getHandPattern() > (int)getHandPattern() )
        return LOSE;

    if( player.totalPips() > totalPips() )
        return WIN;
    else if( player.totalPips() < totalPips() )
        return LOSE;

    return TIE;
}


// start a new game(round)
// before starting a new game(round), you should have
// a new deck, and then shuffle it.
// The deck only has pips A, 9, 10, J, Q, K.
void
SHDealer::start()
{
	SHPlayer::start();

    for( int i = 0; i < 4; i++ )                // A
        cardId[i] = i;
    for( int i = 4, j = 32; j < 52; i++, j++ )  // 9, 10, J, Q, K
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
	SHPlayer::openFirstCard();
}


// show the dealer's hand to the screen
void
SHDealer::showCards() const
{
	SHPlayer::showCards();
}
