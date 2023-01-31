/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     RandomNum.cc
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Nov 29, 1998: Created.
***************************************************************************/

/* $Log: RandomNum.cc,v $
 * Revision 1.1  1998/11/30 01:58:55  li
 * Initial revision
 * */

#include <stdlib.h>
#include "RandomNum.h"

RandomNum::RandomNum(int seed) {

    srand(seed);

}

int
RandomNum::getRandomNum(int low, int high) const {

    int k;
    double d;

    d = (double) rand()/((double)RAND_MAX+1);
    k = (int)(d*(high-low+1));
    return low+k;

}
