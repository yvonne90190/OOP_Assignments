/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     RandomNum.h
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Nov 29, 1998: Created.
***************************************************************************/

/* $Log: RandomNum.h,v $
 * Revision 1.1  1998/11/30 01:58:55  li
 * Initial revision
 * */

#ifndef _RANDOMNUM_H
#define _RANDOMNUM_H

class RandomNum {

public:
    RandomNum(int seed=0);
    int getRandomNum(int low, int high) const; 
};

#endif // _RANDOMNUM_H
