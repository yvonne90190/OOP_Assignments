/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */

#include <iostream>
#include <cstring>
#include <cassert>
#include <algorithm>
#include "AnsiPrint.h"
#include "Card.h"
#include "CardPattern.h"
#include "SHPlayer.h"


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
	name = new char[strlen(playerName)+1];
	strcpy(name, playerName);
	cards = new Card[kMaxCards];
	sortedCards = new Card[kMaxCards];
}

// destructor
SHPlayer::~SHPlayer()
{
	delete [] name;
	delete [] cards;
	delete [] sortedCards;
}

// initialize the number of cards to 0
void
SHPlayer::start()
{
	// restart
	// initialize a new hand of card
	for(int i=0; i<kMaxCards; ++i){   
		cards[i] = 0;
		sortedCards[i] = 0;
	}
	kCurrentCards = 0;
	showFirstCard = false;
	totalCardPips = 0;
}

// add a new card to the current hand
// need to protect the array from overflowing
void SHPlayer::addCard(Card newCard)
{
	// protect array overflowing
	if (kCurrentCards >= kMaxCards)
		return;
	// add to the current hand
	cards[kCurrentCards] = newCard;
	++kCurrentCards;
	//newCard.getPip(): 0~12
	if ( newCard.getPip() == 1){
		totalCardPips += 14;
	}
	else{
		totalCardPips += (newCard.getPip() + 1);
	}
}

// open the first card so it faces up
void
SHPlayer::openFirstCard()
{
	showFirstCard = true;
}

// print the current hand to the screen graphically
void
SHPlayer::showCards() const
{
	for (int h = 0; h < kCardHeight; ++h){       // the hth line of the card height
		for (int i = 0; i < kCurrentCards; ++i){     // the ith card
			int card_pip = cards[i].getPip();
            int card_suit = cards[i].getSuit();
			if ( i==0 ){
				if ( h < int (strlen(name)) ){ 
					cout << name[h] << " ";
				}
				else{
					cout << "  ";
				}
				if (!showFirstCard){
					card_pip = 13;
				}
			}
			string line = card[card_pip][h];       //print the card in string type
			replace(line.begin(), line.end(), 'x', cardAbbrev[card_suit]);
            AnsiPrint(line.c_str(), cardColor[card_suit], white);
            cout << " ";
        }
        cout << endl;
    }
}

// get the total points of the current hand
int
SHPlayer::totalPips() const
{
	return totalCardPips;
}

// judge what kind of hand type you own
// you need to have 5 cards
HandType
SHPlayer::getHandPattern() 
{
	// sort first
	this->sortCards();
	// judge handtype
	if(isStraight())
		return STRAIGHT_FLUSH;
	if(isFourOfAKind())
		return FOUR_OF_A_KIND;
	if(isFullHouse())
		return FULL_HOUSE;
	if(isFlush())
		return FLUSH;
	if(isStraight())
		return STRAIGHT;
	if(isStraight())
		return STRAIGHT;
	if(isThreeOfAKind())
		return THREE_OF_A_KIND;
	if(isTwoPair())
		return TWO_PAIR;
	if(isOnePair())
		return ONE_PAIR;

	return OTHER;
}

// return the number of cards at hand
int
SHPlayer::getNumCards() const
{
	return kCurrentCards;
}
bool cmp(const Card& a, const Card& b){
	// ascending
	return a.getID() < b.getID();
}

void
SHPlayer::sortCards() 
{	
	// 0 ~ 51 ascending
	// sortedCards
	for(int i=0; i<5; ++i){
		sortedCards[i] = cards[i];
	}
	sort(sortedCards, sortedCards + kMaxCards, cmp);
}

// any five card sequence of same suit
bool 
SHPlayer::isStraightFlush() const
{
	if(isStraight() && isFlush()){
    	return true;
    }
    return false;
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


