#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>

template <typename T>
class Node{
	public:
		Node();
		Node(T value_){
			value = value_;
			next = nullptr;
		};
		~Node(){ delete next; };
	public:
		Node<T>* next;
		T value;
};

template <typename T>
class Queue{
	public:
		Queue();
		~Queue(){};
		Queue(const Queue& other); // copy constructor
		Queue& operator=(const Queue&);
		void enqueue(T value);
		void dequeue(int num);
		void printQueue();
	private:
		Node<T>* headPtr;
		Node<T>* tailPtr;
};
#endif
