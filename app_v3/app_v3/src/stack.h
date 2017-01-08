#ifndef STACK_H
#define STACK_H
#include "./utils.h"

class Stack{
	struct nod *firstElement;

	public:
	Stack();
	bool isEmpty() const {return firstElement==nullptr;}
	void pushStack(const int&);
	int popStack();
};

#endif
