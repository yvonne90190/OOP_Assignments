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
        void openFirstCard();

        /**
         * print all cards of the current hand to the screen graphically
         */
        void showCards() const;

        /**
         * get the total points of the current hand
         */
        int totalPips() const;

        /**
         * judge what kind of hand type player owns
         */
        HandType getHandPattern();

        /**
         * return the number of cards at hand
         */
        int getNumCards() const;

    private:
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
        char *name;                         // name of player

        static const int kMaxCards = 5;     // maximal number of cards I can hold
        int nCards;                         // current number of cards at hand
        Card cards[kMaxCards];              // the current hand
        Card sortedCards[kMaxCards];        // sorted cards
        bool showAll;   // a flag indicating the first cards is facing up or down   

};

#endif // _SHPLAYER_H_
