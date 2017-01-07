#include "./stack.h"

void pushStack(nod** prim, const int& value) {
    nod* newNode;

    newNode = new nod;
    newNode->value = value;
    newNode->next = *prim;
    *prim = newNode;
}

int popStack(nod** prim) {
    if (!(*prim))
        return -1;

    nod* aux = *prim;
    int result = (*prim)->value;
    *prim = (*prim)->next;
    delete aux;
    return result;
}