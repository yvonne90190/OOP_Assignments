/* Copyright (c) 1999 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
  NAME
  Cards.cc
  NOTE
  You are asked to design this module.
  You need to draw the given number of cards and print them out.
  Assume that you are given a deck of 52 cards. The cards do not reappear.
  That is, you do not put a card back into the deck after it is drawn.
 ***************************************************************************/
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include "Cards.h"
#include "AnsiPrint.h"
#include <typeinfo>

using namespace std;

const int kNCardPerRow = 5;
const char suitAbbrev[]="SCHD";
const color suitColor[]={black, black, red, red};

int
DrawRandCard(void) {
	return rand() % kNCards;
}

// Print all the cards in record[]
void
PrintCards(int nCards, int* record) {
	for (int i = 0; i < nCards; i += kNCardPerRow) {              // Print kNCardPerRow cards at once, this is the ith row
		for (int h = 0; h < kCardHeight; ++h) {                   // Print kNCardPerRow cards row by row (kCardHeight times)
			for (int j = i; j<i+kNCardPerRow && j<nCards; ++j){   // The jth card in this row
				int pip = record[j] % kNPip;                                
				int suit = record[j] / kNPip;                     // Calculate the pip and suit that corresponds to the ID that were in record[]
				string line = card[pip][h];	
				replace(line.begin(), line.end(), 'x', suitAbbrev[suit]);
				AnsiPrint(line.c_str(), suitColor[suit], white);         
				cout << " ";	
			}	
			cout << endl;
		}
	}
}

