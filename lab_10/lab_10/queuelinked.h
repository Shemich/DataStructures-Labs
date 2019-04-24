// Simulates the flow of customers through a line in a store.
#include "pch.h"
#include <iostream>
#include <cstdlib> // for function rand()
#include <iomanip> // for setprecision manipulator

using namespace std;

template<class DT> // Forward declaration of the Queue class
class Queue;

template<class DT> // Facilitator class for the Queue class
class QueueNode {
private:
	// Constructor
	QueueNode(const DT &nodeData, QueueNode *nextPtr);

	QueueNode(const DT &nodeData);

	QueueNode();

	// Data members
	DT dataItem = 0;
	QueueNode *next = 0;

	friend class Queue<DT>;
};

template<class DT>
class Queue {
public:
	// Constructor
	Queue();

	// Destructor
	~Queue();

	void clear();

	// Queue manipulation operations
	void enqueue(const DT &newData); // Enqueue data item
	DT dequeue(); // Dequeue data data item
	// Queue status operations
	bool isEmpty() const; // Queue is empty
	int getLength() const; // Length of queue
	void show();

private:
	// Data members
	QueueNode<DT> *front, // Pointer to the front node
		*rear; // Pointer to the rear node
};

template<class DT>
Queue<DT>::Queue()
{
	front = NULL;
	rear = NULL;
}

template<class DT>
void Queue<DT>::enqueue(const DT &newData) {
	if (front == NULL) {
		front = new QueueNode<DT>(newData);
		rear = front;
	}
	else {
		QueueNode<DT> *tmp;
		tmp = new QueueNode<DT>(newData, front);
		front = tmp;
	}
}

template<class DT>
bool Queue<DT>::isEmpty() const
{
	if (front == NULL)
		return true;
	else
		return false;
}

template<class DT>
DT Queue<DT>::dequeue() {
	QueueNode<DT> *tmp;
	tmp = new QueueNode<DT>;
	tmp = front;
	front = front->next;
	DT value = tmp->dataItem;
	delete tmp;
	return value;
}

template<class DT>
int Queue<DT>::getLength() const
{
	int i = 0;
	QueueNode* temp = front;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return i;
}

template<class DT>
void Queue<DT>::clear() {
	QueueNode<DT> *current = front;
	while (front) {
		current = current->next;
		delete front;
		front = current;
	}
	front = NULL;
	rear = NULL;
}

template<class DT>
Queue<DT>::~Queue()
{
	QueueNode<DT> *current = front;
	while (front) {
		current = current->next;
		delete front;
		front = current;
	}
	front = 0;
	rear = 0;
}

template<class DT>
QueueNode<DT>::QueueNode(const DT &nodeData, QueueNode *nextPtr) {
	dataItem = nodeData;
	next = nextPtr;
}

template<class DT>
QueueNode<DT>::QueueNode(const DT &nodeData) {
	dataItem = nodeData;
	next = 0;
}

template<class DT>
QueueNode<DT>::QueueNode() {
	dataItem = 0;
	next = 0;
}
#pragma once#pragma once
