/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */

#include <cassert>
#include "Card.h"

using namespace std;

// constructor
Card::Card(int newId)
{
    setID(newId);
}

int
Card::getID() const 
{
    return id;
}

// get the pip of the card (0-12)
int
Card::getPip() const
{
    return id / kNSuit;
}

// get the suit of the card (0-3)
int
Card::getSuit() const
{
    return id % kNSuit;
}

// set id directly
void
Card::setID(int newId)
{
    assert( (newId >= 0) && (newId < kNCards) );
    id = newId;
}

