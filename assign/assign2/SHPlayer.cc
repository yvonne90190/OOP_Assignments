/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */

#include <iostream>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <cstring>
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
	cards = new Card[kMaxCards];
	sortedCards = new Card[kMaxCards];
}
// destructor
SHPlayer::~SHPlayer()
{
	delete [] cards;
	delete [] sortedCards;
}
// initialize the number of cards to 0
// drawn up to kMaxCards num of random cards
void
SHPlayer::start()
{
	numAtHand = 0;             
	bool been_drawn[52] = {false};   // mark what card have been drawn
	for (; numAtHand<kMaxCards; ++numAtHand){    
		int ID = rand() % 52;           // select a random ID     
		if ( been_drawn[ID]==true ){	// if the card have been drawn, draw it again
			numAtHand--;
		} 
		else {
			Card new_card(ID);	// make a new card by ID
			addCard(new_card);	// add the card to hand
			been_drawn[ID] = true;	
		}
	}	
}

// add a new card to the current hand
// need to protect the array from overflowing
void SHPlayer::addCard(Card newCard)
{	
	cards[numAtHand] = newCard;
}

// open the first card so it faces up
void
SHPlayer::openFirstCard(int i, bool showFirst, int &card_pip) const
{
   if ( i == 0 && showFirst == false ){ 
   	card_pip = 13;  // the 13th in CardPattern
   }
}

// print the current hand to the screen graphically
void
SHPlayer::showCards(bool showFirst) const
{
	for (int h = 0; h < kCardHeight; ++h){       // the hth line of the card height
		for (int i = 0; i < kMaxCards; ++i){     // the ith card
			int card_pip = cards[i].getPip();   
			int card_suit = cards[i].getSuit();
			openFirstCard(i, showFirst, card_pip); // check if open the first card 
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
	int sum = 0;
	for (int i=0; i<kMaxCards; ++i){
		sum += cards[i].getPip();       // sum up the pips
	}
	return sum+kMaxCards;  // +5 (Correction) because the card[][][] in CardPattern.h,  pip = 1 start at card[0][][]
}

// judge what kind of hand type you own
// you need to have 5 cards
HandType
SHPlayer::getHandPattern()  
{	
	sortCards();
	if ( isStraightFlush() ){
		return STRAIGHT_FLUSH;
	}
	else if ( isFourOfAKind() ){
		return FOUR_OF_A_KIND;
	}
	else if ( isFullHouse() ){
		return  FULL_HOUSE;
	}
	else if ( isFlush() ){
		return FLUSH;
	}
	else if ( isStraight() ){
		return STRAIGHT;
	}
	else if ( isThreeOfAKind() ){
		return THREE_OF_A_KIND;
	}
	else if ( isTwoPair() ){
		return TWO_PAIR;
	}
	else if ( isOnePair() ){
		return ONE_PAIR;
	}
	else{
		return OTHER;	
	}
}

void 
SHPlayer::showPattern() 
{
	cout << HandTypeName[getHandPattern()];
}

// return the number of cards at hand
int
SHPlayer::getNumCards() const
{
	return numAtHand;
}

// sort the cards in assending order according to their ID
bool cmp( Card a, Card b ){
	return a.getID() < b.getID();
}

void
SHPlayer::sortCards() 
{
	for ( int i=0; i<kMaxCards; ++i){   // copy the cards[] to sortCards[]
		sortedCards[i] = cards[i];
	}
	sort(sortedCards, sortedCards+kMaxCards, cmp);  // sort the sortedCards[]
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


