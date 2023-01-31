/* Copyright (c) 1999 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     CardTest.cc
   PURPOSE
     Testing card displaying
   NOTES

   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 7, 1999: Created.
***************************************************************************/

/* $Log:$ */

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <assert.h>
}

#include <iostream>
#include "AnsiPrint.h"
#include "Cards.h"
//#include "Cards.cc"

using namespace std;

/**
 * Print my id 
 */
void
PrintMyID(const char *studId) {

  char *str= new char[sizeof(studId)+5];
  // we put string in a buffer first 
  sprintf(str,"ID: %s",studId);
  // print the buffer out with color
  AnsiPrint(str,yellow,red, true, true);
  cout << endl << endl;
  delete [] str;

}


/**
 * PrintUsage
 */
void
PrintUsage(const char *progName) {

  assert(progName);
  cout << "Usage: " << progName << " NCards [Seed]" << endl;

}

/**
 * Main Function Call
 */
int
main(int argc, char **argv) {
  int ncards=0;  // number of cards to draw  
  if (argc==3) {
	long seed=atoi(argv[2]); // the third argument is the seed
    srand(seed);
    ncards=atoi(argv[1]); // the second argument is the number of cards
  } else if (argc==2) {
    ncards=atoi(argv[1]);
  } else {
    PrintUsage(argv[0]);
    exit(-1);
  }

  // You are asked to fill in a few missing statements here

  // Warn and exit when the number of cards ask to display exceed 52
  if (ncards>kNCards) {                          
  	cout << "Sorry, number of cards can not exceed 52." << endl;
	exit(-1);
  }  

  // Draw ncards random cards, no repeat  
  bool been_drawn[kNCards]={false};   // Mark the card that had been drawn as true
  int record[ncards]={};              // Record the ID(1~52) of the card that was drawn

  for (int i=0; i<ncards; ++i) {    
	int ID = DrawRandCard();
	if (been_drawn[ID]==true) {   	// If the card had been drawn, draw one more time
		i--;
	} else { 						// If get a valid card, record the number of it in record[] 
		record[i]=ID;
		been_drawn[ID]=false;
	}
  }

  // Print out all the cards that were recorded in ...
  PrintCards(ncards, record);

  // Print my id at the end of the program
  PrintMyID("109208064");

  return 0;

}
