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
#include <string.h>
}

#include <iostream>
#include <fstream>
#include "AnsiPrint.h"
#include "Queue.h"
#include "Queue.cc"
using namespace std;

/**
 * Print my id 
 */
void
PrintMyID(const char *studId) {

  char *str= new char[strlen(studId)+5];
  sprintf(str,"ID: %s",studId);
  AnsiPrint(str, yellow, red, true, true);
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

	istream *is1=&cin, *is2=&cin;

	if (argc>3 || argc<2) {
		PrintUsage(argv[0]);
		exit(-1);
	} else if (argc>2) {
		is2 = new ifstream(argv[2]);
		if (is2->fail()) {
			cerr << "Can't open file " << argv[2] << endl;
			exit(1);
		}
	} 
	if (argc>1) {
		is1 = new ifstream(argv[1]);
		if (is1->fail()) {
			cerr << "Can't open file " << argv[1] << endl;
			exit(2);
		}
	}

	// You need to provide testing exercises here
	Queue<int> *myIntQPtr =new Queue<int>;
	// test integer queue

	// enqueue exercises on myIntQPtr
	int x;
	while (*is1 >> x)
    {	try{
        	myIntQPtr->enqueue(x);
		}
		catch (const Except& except){
			AnsiPrint(except, red, yellow, true, false);
			cout << endl;
		}
	}
	
	// test copy constructor
	Queue<int> myIntQ = *myIntQPtr;
	// test destructor
	delete myIntQPtr;
	cout << "myIntQ : " << endl;
	try{
		myIntQ.printQueue();
	}
	catch (const Except& except){
		AnsiPrint(except, red, yellow, true, false);
		cout << endl;
	}
		
	cout << endl;
	// dequeue exercises on myIntQ
	try{
		myIntQ.dequeue(4);
	}
	catch (const Except& except){
		AnsiPrint(except, red, yellow, true, false);
		cout << endl;
	}
	cout << endl << "myInt after dequeue" << endl;
	try{
		myIntQ.printQueue();
	}
	catch (const Except& except){
		AnsiPrint(except, red, yellow, true, false);
		cout << endl;
	}
	//test character queue
	Queue<char> myCharQ, myCharQ1;
	// enqueue exercises on myCharQ
	char y;
	int cnt;
	while (*is2 >> y)
    {
		cnt++;
		try{
        	myCharQ.enqueue(y);
		}
		catch (const Except& except){
			AnsiPrint(except, red, yellow, true, false);
			cout << endl;
		}
	}
	cout << endl << "myCharQ : " << endl;
	try{
		myCharQ.printQueue();
	}
	catch (const Except& except){
		AnsiPrint(except, red, yellow, true, false);
		cout << endl;
	}
	cout << endl;
	
	// test assignment operator
	myCharQ1=myCharQ;
	cout << endl << "myCharQ1 : " << endl;
	try{
		myCharQ1.printQueue();
	}
	catch (const Except& except){
		AnsiPrint(except, red, yellow, true, false);
		cout << endl;
	}
	// dequeue exercise on myCharQ1
	cout << endl;
	try{	
		myCharQ1.dequeue(cnt);
	}
	catch (const Except& except){
		AnsiPrint((const char*)except, red, yellow, true, false);
		cout << endl;
	}
	cout << endl << "myCharQ1 after dequeue" << endl;
	try{	
		myCharQ1.printQueue();
	}
	catch (const Except& except){
		AnsiPrint((const char*)except, red, yellow, true, false);
		cout << endl;
	}
		
	// dequeue an empty queue to throw an exception
	cout << endl;
	try{	
		myCharQ1.dequeue(1);
	}
	catch (const Except& except){
		AnsiPrint((const char*)except, red, yellow, true, false);
		cout << endl;
	}
	cout << endl << "myCharQ1 after dequeue" << endl;
	try{	
		myCharQ1.printQueue();
	}
	catch (const Except& except){
		AnsiPrint((const char*)except, red, yellow, true, false);
		cout << endl;
	}
		
	PrintMyID("109208064");
	return 0;
    
}
