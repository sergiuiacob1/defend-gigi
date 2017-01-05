#ifndef STACK_H
#define STACK_H

struct nod{
	int value;
	struct nod *next;
};

void pushStack(nod**, const int&);
int popStack(nod**);

#endif
