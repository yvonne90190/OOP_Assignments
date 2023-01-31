/* Copyright (c) 2003 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     Except.h
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - May 30, 2003: Created.
***************************************************************************/

/* $Log:$ */

#ifndef _EXCEPT_H
#define _EXCEPT_H

class Except {
public:
  Except(const char *str);
  operator const char*() const {return error;} 
private:
  char *error;

};

#endif
