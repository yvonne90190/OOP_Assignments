/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     QueueTest.cc
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Dec 11, 1998: Created.
***************************************************************************/

/* $Log:$ */

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <strings.h>
}

#include <iostream>
#include <cstring>
#include <fstream>
#include "AnsiPrint.h"
#include "Queue.cc"
#include "Except.h"

using namespace std;

/**
 * Print my id 
 */

void
PrintMyID(const char *studId) {

  char *str= new char[strlen(studId)+5];
  sprintf(str,"ID: %s",studId);
  AnsiPrint(str,yellow,red,true, true);
  cout << endl ;
  delete [] str;

}

/**
 * PrintUsage
 */

void
PrintUsage(const char *progName) {

    assert(progName);
    cout << "Usage: " << progName << " intfile [charfile]" << endl;

}

int
main(int argc, char **argv) {

  istream *is1=&cin,*is2=&cin;

  if ((argc>3)||(argc==1)) {
    PrintUsage(argv[0]);
    exit(-1);
  } else if (argc>2) {
    is2 = new ifstream(argv[2]);
    if(!(*is2)) {
      cerr << "Can't open file " << argv[2] << endl;
      exit(1);
    }
  } 
  if (argc>1) {
    is1 = new ifstream(argv[1]);
    if (!(*is1)) {
      cerr << "Can't open file " << argv[1] << endl;
      exit(2);
    }
  }

  try {
    // Integer Queue
    Queue<int> *myIntQ=new Queue<int>;
    int tmp1;
    while (1) {
      *is1 >> tmp1;
      if (!is1->good()) break;
      myIntQ->enqueue(tmp1);
    }
    Queue<int> myIntQ1 = *myIntQ;
    delete myIntQ;
    AnsiPrint("Integer Queue:",yellow,black,true,false);
    cout << endl;
    //cout << "Integer Queue: " << endl;
    while (!myIntQ1.isEmpty()) {
      cout << myIntQ1.dequeue() << endl;
    }
    // Character Queue
    Queue<char> myCharQ, myCharQ1;
    char tmp2;
    while (1) {
      *is2 >> tmp2;
      if (!is2->good()) break;
      myCharQ.enqueue(tmp2);
    }
    myCharQ1=myCharQ;
    AnsiPrint("Character Queue:",yellow, black, true, false);   
    cout << endl;
    //cout << "Character Queue: " << endl;
    while (!myCharQ.isEmpty()) {
      cout << myCharQ.dequeue() << endl;
    }
    // causing an exception
    myCharQ.dequeue();
  } catch(Except &e) {
    AnsiPrint(e,red,yellow,true,false);
    cout << endl ;
  }

  PrintMyID("86701000");
  return 0;
    
}
