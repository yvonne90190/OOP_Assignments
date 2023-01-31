#include "Queue.h"
#include <iostream>
#include "Except.h"
#include <typeinfo>  //for 'typeid' to work

using namespace std;
/*
 * Constructor
 * */
template <typename T>
Queue<T>::Queue(){
	headPtr = nullptr;
	tailPtr = nullptr;	
	// TEST INT and CHAR QUEUE
}

/*
 * Copy Consturctor
 * */
template <typename T>
Queue<T>::Queue(const Queue& other) {
	this->headPtr = other.headPtr;
	this->tailPtr = other.tailPtr;
}

/*
 * Copy Assignment Operator
 * */
template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other) {
	 if (&other != this) {
		this->headPtr = nullptr;
		this->tailPtr = nullptr;
		Node<T>* tmp2 = other.headPtr;  //counter
		while(tmp2){
			this->enqueue(tmp2->value);
			tmp2 = tmp2->next;
		}
	 }
	 return *this;
}

/*
 * Enqueue
 * */
template <typename T>
void Queue<T>::enqueue(T value) {
	if (headPtr != nullptr && tailPtr == nullptr){
		throw Except("Incorrect head or tail pointers in the queue, (headPtr != nullptr) but (tailPtr == nullptr)");
	}
	if (headPtr == nullptr && tailPtr != nullptr){
		throw Except("Incorrect head or tail pointers in the queue, (headPtr == nullptr) but (tailPtr != nullptr)");
	}
	Node<T>* newNode = new Node<T>(value);
	if (newNode == NULL){
		throw Except("Can not allocate more memory in enqueue operation");
	}	
	// if the original queue is no empty, connect newNode with the last node
	if (tailPtr == nullptr){
		headPtr = newNode;
		tailPtr = newNode;
	}
   	else{
		tailPtr->next = newNode;
		tailPtr = newNode;	
	}
}

/*
 * Dequeue
 * */
template <typename T>
void Queue<T>::dequeue(int num) {
	cout << "Dequeue " << num << " times : " << endl;
	for (int i=0; i<num; ++i) {
		if (headPtr == nullptr){
			tailPtr = nullptr;
		}
		if (headPtr != nullptr && tailPtr == nullptr){
			throw Except("Incorrect head or tail pointers in the queue, (headPtr != nullptr) but (tailPtr == nullptr)");
		}
		if (headPtr == nullptr && tailPtr != nullptr){
			throw Except("Incorrect head or tail pointers in the queue, (headPtr == nullptr) but (tailPtr != nullptr)");
		}
		if ( headPtr == nullptr && tailPtr == nullptr){
		    throw Except("Unavailable to dequeue an empty queue");
		}
		// set the head to next node
		try{
			this->printQueue();
		}
		catch (char const* cerr){
			throw;		
		}
		headPtr = headPtr->next;
	}
}

/*
 * Print out the current Queue
 * */
template <typename T>
void Queue<T>::printQueue() {
	if (headPtr != nullptr && tailPtr == nullptr){
		throw Except("Incorrect head or tail pointers in the queue, (headPtr != nullptr) but (tailPtr == nullptr)");
	}
	if (headPtr == nullptr && tailPtr != nullptr){
		throw Except("Incorrect head or tail pointers in the queue, (headPtr == nullptr) but (tailPtr != nullptr)");
	}
	Node<T>* tmpPtr = this->headPtr;
	while (tmpPtr != nullptr) {
		cout << tmpPtr->value << " ";
		if (tmpPtr->next == nullptr){
			break;
		}
		tmpPtr = tmpPtr->next;
	}
	cout << endl;
}














