/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */

#include <iostream>
#include <cstring>
#include <cassert>
#include "Card.h"
#include "CardPattern.h"
#include "SHPlayer.h"
#include "AnsiPrint.h"

using namespace std;

const char* HandTypeName[9] = {
    "Straight flush",
    "Four of a kind",
    "Full house",
    "Flush",
    "Straight",
    "Three of a kind",
    "Two pair",
    "One pair",
    "Other"
};

// constructor
SHPlayer::SHPlayer(const char* playerName)
{
    name = strdup(playerName);
    start();
}

// initialize the number of cards to 0
void
SHPlayer::start()
{
    nCards = 0;
    showAll = false;
}

// add a new card to the current hand
// need to protect the array from overflowing
void SHPlayer::addCard(Card newCard)
{
    if( nCards < kMaxCards ) {
        cards[nCards++] = newCard;
    }
    else {
        cout << "Error: Exceed the maximal number of cards a player can have."
            << endl;
    }
}

// open the first card so it faces up
void
SHPlayer::openFirstCard()
{
    showAll = true;
}

// print the current hand to the screen graphically
void
SHPlayer::showCards() const
{
    char line[kCardWidth + 1];

    for( int n = 0; n < nCards; n += kNCardPerRow ) {
        for( int height = 0; height < kCardHeight; height++ ) {
            for( int i = n; i < n + kNCardPerRow && i < nCards; i++ ) {
                int pip = (i == 0 && !showAll) ? 13 : cards[i].getPip();
                int suit = cards[i].getSuit();
                for( int width = 0; width < kCardWidth; width++ ) {
                    line[width] = card[pip][height][width];
                    if( line[width] == 'x' )
                        line[width] = cardAbbrev[suit];
                }
                line[kCardWidth] = '\0';
                AnsiPrint(line, cardColor[suit], white);
                cout << " ";
            }
            cout << endl;
        }
    }
}

// get the total points of the current hand
int
SHPlayer::totalPips() const
{
    int cnt = 0;
    for( int i = 0; i < nCards; i++ )
        cnt += cards[i].getPip() + 1;

    return cnt;
}

// judge what kind of hand type you own
// you need to have 5 cards
HandType
SHPlayer::getHandPattern() 
{
    assert( nCards == 5 );

    sortCards();

    if( isStraightFlush() )
        return STRAIGHT_FLUSH;
    if( isFourOfAKind() )
        return FOUR_OF_A_KIND;
    if( isFullHouse() )
        return FULL_HOUSE;
    if( isFlush() )
        return FLUSH;
    if( isStraight() )
        return STRAIGHT;
    if( isThreeOfAKind() )
        return THREE_OF_A_KIND;
    if( isTwoPair() )
        return TWO_PAIR;
    if( isOnePair() )
        return ONE_PAIR;

    return OTHER;
}

// return the number of cards at hand
int
SHPlayer::getNumCards() const
{
    return nCards;
}

inline void
swap(Card& a, Card& b)
{
    Card tmp = a;
    a = b;
    b = tmp;
}

void
SHPlayer::sortCards() 
{
    // copy to sortedCards
    for( int i = 0; i < kMaxCards; i++ )
        sortedCards[i] = cards[i];

    // bubble sort
    for( int i = 0; i < kMaxCards - 1; i++ )
        for( int j = 0; j < kMaxCards - i - 1; j++ ) 
            if( sortedCards[j].getPip() > sortedCards[j+1].getPip() )
                swap(sortedCards[j], sortedCards[j+1]);
}

// any five card sequence of same suit
bool 
SHPlayer::isStraightFlush() const
{
    return isStraight() && isFlush();
}

// four cards of the same pip
bool 
SHPlayer::isFourOfAKind() const
{
    // O O O O X
    if( sortedCards[0].getPip() == sortedCards[1].getPip() &&
            sortedCards[2].getPip() == sortedCards[3].getPip() &&
            sortedCards[0].getPip() == sortedCards[2].getPip() )
        return true;
    // X O O O O
    if( sortedCards[1].getPip() == sortedCards[2].getPip() &&
            sortedCards[3].getPip() == sortedCards[4].getPip() &&
            sortedCards[1].getPip() == sortedCards[3].getPip() )
        return true;

    return false;
}

// three of a kind combined with a pair
bool 
SHPlayer::isFullHouse() const
{
    // O O O X X
    if( sortedCards[0].getPip() == sortedCards[1].getPip() &&
            sortedCards[1].getPip() == sortedCards[2].getPip() &&
            sortedCards[3].getPip() == sortedCards[4].getPip() )
        return true;
    // X X X O O
    if( sortedCards[0].getPip() == sortedCards[1].getPip() &&
            sortedCards[2].getPip() == sortedCards[3].getPip() &&
            sortedCards[3].getPip() == sortedCards[4].getPip() )
        return true;

    return false;
}

// five cards of the same suit
bool
SHPlayer::isFlush() const
{
    for( int i = 0; i < kMaxCards - 1; i++ )
        if( sortedCards[i].getSuit() != sortedCards[i+1].getSuit() )
            return false;

    return true;
}

// five cards in sequence
bool 
SHPlayer::isStraight() const
{
    for( int i = 0; i < kMaxCards - 1; i++ )
        if( sortedCards[i].getPip() + 1 != sortedCards[i+1].getPip() )
            return false;

    return true;
}

// three cards of the same pip
bool 
SHPlayer::isThreeOfAKind() const
{
    for( int i = 0; i < kMaxCards - 2; i++ )
        if( sortedCards[i].getPip() == sortedCards[i+1].getPip() &&
                sortedCards[i].getPip() == sortedCards[i+2].getPip() )
            return true;

    return false;
}

// two cards of one pip, two cards of another pip
bool 
SHPlayer::isTwoPair() const
{
    // O O @ @ X
    if( sortedCards[0].getPip() == sortedCards[1].getPip() &&
            sortedCards[2].getPip() == sortedCards[3].getPip() )
        return true;
    // O O X @ @
    if( sortedCards[0].getPip() == sortedCards[1].getPip() &&
            sortedCards[3].getPip() == sortedCards[4].getPip() )
        return true;
    // X O O @ @
    if( sortedCards[1].getPip() == sortedCards[2].getPip() &&
            sortedCards[3].getPip() == sortedCards[4].getPip() )
        return true;

    return false;
}

// two cards of one pip
bool 
SHPlayer::isOnePair() const
{
    for( int i = 0; i < kMaxCards - 1; i++ )
        if( sortedCards[i].getPip() == sortedCards[i+1].getPip() )
            return true;

    return false;
}

