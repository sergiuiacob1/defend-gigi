#include "./stack.h"

Stack::Stack(){
    firstElement = nullptr;
}

void Stack::pushStack(const int& value) {
    nod* newNode;

    newNode = new nod;
    newNode->value = value;
    newNode->next = firstElement;
    firstElement = newNode;
}

int Stack::popStack() {
    if (this->isEmpty())
        return -1;

    nod* aux = firstElement;
    int result = firstElement->value;
    firstElement = firstElement->next;
    delete aux;
    return result;
}