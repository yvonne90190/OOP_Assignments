/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     AnsiPrint.h
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 12, 1998: Created.
***************************************************************************/

/* $Log: AnsiPrint.h,v $
 *
 * */

#ifndef _ANSIPRINT_H
#define _ANSIPRINT_H

enum color {black=0, red, green, yellow, blue, pink, cyan, white, nochange};

// format and print a string with the given ansi coloring options
void AnsiPrint(const char *str, color fg, color bg=white, 
	       bool hi=false, bool blinking=false);
void AnsiPrint(const char *str, bool hi=false, bool blinking=false);

#endif
