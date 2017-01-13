#ifndef QUEUE_H
#define QUEUE_H
#include "./utils.h"

class Queue{
	struct nod *firstElement, *lastElement;

	public:
	Queue();
	bool isEmpty() const {return firstElement==nullptr;}
	void pushQueue (const int&);
	int popQueue();
};

#endif
