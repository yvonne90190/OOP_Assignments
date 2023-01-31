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

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <cstring>
#include "AnsiPrint.h"
#include "Cards.h"

using namespace std;
/**
 * Print my id 
 */
void
PrintMyID(const char *studId) {

    char *str= new char[strlen(studId) + 1];
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

    if (ncards>kNCards) {
        cout << "Sorry, number of cards can not be greater than 52." << endl;
        exit(-2);
    }

    int i;
    int *cardID = new int[ncards];
    int drawn[kNCards];
    int curCard;

    for(i=0;i<kNCards;i++) 
        drawn[i]=false;

    i=0;
    while(i<ncards) {
        // draw cards randomly
        curCard = DrawRandomCard();
        if (drawn[curCard]) 
            continue;
        else { 
            cardID[i]=curCard;
            drawn[curCard]=true;
            i++;
        }
    }

    // Print out all the cards
    PrintCards(ncards, cardID);

    delete [] cardID;

    // Print my id at the end of the program
    PrintMyID("u1234567");

    return 0;

}
