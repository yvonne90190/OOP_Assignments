/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */

#ifndef _SHPLAYER_H_
#define _SHPLAYER_H_


#include "Card.h"


enum HandType {
    STRAIGHT_FLUSH,
    FOUR_OF_A_KIND,
    FULL_HOUSE,
    FLUSH,
    STRAIGHT,
    THREE_OF_A_KIND,
    TWO_PAIR,
    ONE_PAIR,
    OTHER
};

extern const char* HandTypeName[9];

/**
 * class to simulate a show hand game player
 * A show hand player
 * 1. knows how to start a new game,
 * 2. add a new card to the current hand,
 * 3. judge what kind of hand type he/her owns,
 * 4. shows his/her cards to the screen with the first card facing up or down.
 */
class SHPlayer {

    public:
        /**
         * all initialization should be in this constructor
         */
        SHPlayer(const char *playerName);
	/**
	 *  sestructor
	*/
	~SHPlayer();
	/**
         * start a new hand
         */ 
        void start();

        /**
         * add a card to the end of the current hand
         */
        void addCard(Card newCard);

        /**
         * open the first card so it faces up
         */
        void openFirstCard(int i, bool showFirst, int &card_pip) const;

        /**
         * print all cards of the current hand to the screen graphically
         */
        void showCards(bool showFirst) const;

        /**
         * get the total points of the current hand
         */
        int totalPips() const;

        /**
         * determine what kind of hand pattern that the player owns
         */
        HandType getHandPattern();
		void showPattern();
        /**
         * return the number of cards at hand
         */
        int getNumCards() const;

    private:
	/**
	 * sort the current hand of cards in an ascending order and 
	 * store them in the sortedCards array
	 */
        void sortCards() ;
        bool isStraightFlush() const;
        bool isFourOfAKind() const;
        bool isFullHouse() const;
        bool isFlush() const;
        bool isStraight() const;
        bool isThreeOfAKind() const;
        bool isTwoPair() const;
        bool isOnePair() const;

    private:

        static const int kMaxCards = 5;  // maximal number of cards I can hold
		Card *cards;              // the current hand
		Card *sortedCards;        // sorted cards

	// your private/internal stuff goes here
		int numAtHand;  // current num of cards at hand
};

#endif // _SHPLAYER_H_
