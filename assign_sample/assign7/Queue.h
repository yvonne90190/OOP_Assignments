/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     Queue.h
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Dec 11, 1998: Created.
***************************************************************************/

/* $Log:$ */

#ifndef _QUEUE_H
#define _QUEUE_H

template<class T>
class Queue;

template<class T> 
class Data { 
  friend class Queue<T>;
private:
  Data(T value);
  T getValue();
  T value;
  Data<T> *next;
};

template<class T>
class Queue {

public:
  Queue();
  ~Queue();
  Queue(const Queue<T> &src);
  void enqueue(T v);
  T dequeue(); 
  bool isEmpty() const;
  Queue<T> &operator=(const Queue<T> &src);
private:
  Data<T> *head;
  Data<T> *tail;
  void checkInvariant();
};

#endif
