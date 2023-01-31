/* Copyright (c) 1999 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     Cards.cc
   PURPOSE
     Pretty print a poker card to the screen
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 7, 1999: Created.
***************************************************************************/

/* $Log:$ */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "AnsiPrint.h"
#include "Cards.h"

using namespace std;

// data for use with the card printing
const char cardAbbrev[]="SHDC";
// data for use with the card printing
const color cardColor[]={black,red,red,black};
const int kNCardPerRow = 5;

// return a number between 0 and 51
int
DrawRandomCard(void) {
    return rand() % kNCards;
}

void
PrintCards(int nCards, int *cardID) {

    int pip, suit;
    char line[kCardWidth+1];
    for( int n = 0; n < nCards; n += kNCardPerRow ) {
        for( int height = 0; height < kCardHeight; height++, cout<<endl ) {
            for( int i = n; i < n+kNCardPerRow && i < nCards; i++, cout<<" " ) {
                pip = cardID[i] / kNSuit;
                suit = cardID[i] % kNSuit;
                for( int width = 0; width < kCardWidth; width++ ) {
                    line[width]=card[pip][height][width];
                    if( line[width] == 'x' ) 
                        line[width] = cardAbbrev[suit];
                }
                line[kCardWidth]='\0';
                // color print the row and put a space in between
                AnsiPrint(line,cardColor[suit],white);
            }
        }
    }
}
