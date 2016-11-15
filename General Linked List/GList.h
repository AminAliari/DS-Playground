#ifndef GList_h
#define GList_h

#include <iostream>

using namespace std;

class GNode {
public:
    int tag;
    GNode *link;
    
    union {
        GNode *dlink;
        char value;
    };
};

class GList {
    
public:
    GList(string s);
    int depth();
    void print();
    void add(char value);
    void add(GList gl);
    GList();
    
private:
    GNode *first;
    int depth(GNode *p);
    void print(GNode *p,int in);
};



#endif
