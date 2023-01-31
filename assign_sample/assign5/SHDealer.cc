/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */

#include "SHPlayer.h"
#include "SHDealer.h"
#include <cassert>
#include <algorithm>
#include <iostream>


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
// The deck only has pips A, 8, 9, 10, J, Q, K.
void
SHDealer::start()
{
    SHPlayer::start();

    // deal cards that have pips A, 8, 9, 10, J, Q, K
    int id[] = {0, 8, 9, 10, 11, 12};
    for( int i = 0; i < 24; i++ )
        cardId[i] = id[i/Card::kNSuit] * Card::kNSuit + i % Card::kNSuit;

    cardDealt = 0;
    shuffle();
}


// shuffle the deck of cards
void
SHDealer::shuffle()
{
    for( int i = 0; i < nTotalCards; i++ )
        std::swap(cardId[i], cardId[rand() % (nTotalCards - i) + i]);
}



