#ifndef List_h
#define List_h

class Node {
public:
    int value;
    Node *link;
};

class List {
    
public:
    void print();
    void reverse();
    void add(int value);
    List () {
        first = 0;
    }
    
private:
    Node *first;
    void print(Node *p);
};



#endif
