#include <iostream>
#include "List.h"

void List::reverse() {
    Node *r = 0, *q = 0, *p = first;
    
    while (p) {
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    first = q;
}

void List::add(int value) {
    Node *p = new Node();
    p->value = value;
    p->link = first;
    first = p;
}

void List::print() {
    print(first);
}

void List::print(Node *p) {
    if (p) {
        std::cout << p->value << (p->link ? ", " : "\n");
        print(p->link);
    }
}
