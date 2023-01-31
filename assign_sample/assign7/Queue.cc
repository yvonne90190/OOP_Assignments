/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     Queue.cc
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Dec 11, 1998: Created.
***************************************************************************/

/* $Log:$ */

#include "Queue.h"
#include "Except.h"

/* 
 * Constructor of the underlying data in the queue template
 */
template<class T>
Data<T>::Data(T v): value(v), next(NULL) {

}

/* 
 * Accessor function of the underlying data in the queue template
 */
template<class T>
T Data<T>::getValue() {

  return value;

}

/** 
 * Internal class invariant verification routine. It throws a "class
 * invariant violated" message if it happens. 
 */

template<class T>
void Queue<T>::checkInvariant() {

  static Except e("Class invariant violated");
  if ((head==NULL && tail!=NULL) || (head!=NULL && tail==NULL))
    throw(e);

}

/* 
 * Constructor for the template queue class. It
 */
template<class T>
Queue<T>::Queue():  head(NULL), tail(NULL) {

  checkInvariant();

}

/* 
 * Destructor for the template queue class. 
 */
template<class T>
Queue<T>::~Queue() {

  Data<T> *n,*c=head;
  while(c!=NULL) {
    n=c->next;
    delete c;
    c = n;
  }

}

/* 
 * Copy Constructor for the template queue class. 
 */
template<class T>
Queue<T>::Queue(const Queue<T> &src): head(NULL), tail(NULL) {

  Data<T> *tmp;
  for(tmp=src.head; tmp!=NULL; tmp=tmp->next) {
    enqueue(tmp->getValue());
  }
  checkInvariant();
  
}

/* 
 * Assignment operator overloading for the template queue class. 
 */
template<class T>
Queue<T> &Queue<T>::operator=(const Queue<T> &src) {

  checkInvariant();
  if (this == &src) {
    return *this;
  }
  while(!this->isEmpty()) {
    this->dequeue();
  }

  Data<T> *tmp;

  for(tmp=src.head; tmp!=NULL; tmp = tmp->next)
    enqueue(tmp->getValue());

  checkInvariant();

  return *this;

}

/* 
 * isEmpty function for the template queue class. 
 */

template<class T>
bool Queue<T>::isEmpty() const {

  return(head==NULL);

}

/* 
 * Enqueue operation for the template queue class. 
 */
template<class T>
void Queue<T>::enqueue(T v) {

  static Except e("Enqueue failed: no more memory");
  checkInvariant();
  Data<T> *tmp;
  tmp = new Data<T>(v);
  if (tmp==NULL) throw (e);
  if (head==NULL) {
    head = tmp;
  } else {
    tail->next = tmp;
  }
  tail = tmp;
  checkInvariant();

}

/* 
 * Dequeue operation for the template queue class. 
 */
template<class T>
T Queue<T>::dequeue() {

  static Except e("Attempt to dequeue empty queue");
  checkInvariant();
  if (isEmpty()) throw(e);

  T v;
  v = head->value;
  
  Data<T> *tmp = head;
  head = head->next;
  if (head==NULL) tail=NULL;
  delete tmp;

  checkInvariant();

  return v;
  
}


