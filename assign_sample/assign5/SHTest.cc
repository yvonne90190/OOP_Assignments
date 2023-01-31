/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */

#include <cassert>
#include <cstdlib>
#include <iostream>
#include "AnsiPrint.h"
#include "ConsoleMenu.h"
#include "SHPlayer.h"
#include "SHDealer.h"
#include "SHGame.h"

using namespace std;


/**
 * Print my ID
 */
void
PrintMyID(const char* studId)
{
    char *str = new char[sizeof(studId) + 5];
    sprintf(str, "ID: %s", studId);
    AnsiPrint(str, yellow, red, true, true);
    cout << endl << endl;
    delete [] str;
}



/**
 * PrintUsage
 */
void
PrintUsage(const char* progName)
{
    assert(progName);
    cout << "Usage: " << progName << " [Seed]" << endl;
}


/**
 * Main Function Call
 */
int main(int argc, char **argv) 
{
    if( argc > 2 ) {
        PrintUsage(argv[0]);
        exit(-1);
    }
    else if( argc == 2 ) {
        // the first argument is the seed
        long seed = atoi(argv[1]);
        srand(seed);
    }

    // create an instance of player and dealer
    SHPlayer shplayer("Player");
    SHDealer shdealer;

    // create an instance of the show hand game with the given player an dealer
    SHGame shgame(shplayer, shdealer);

    // play the game until the user quit
    while( shgame.oneRun() );

    // put your ID here
    PrintMyID("1017030xx");

    return 0;
}
