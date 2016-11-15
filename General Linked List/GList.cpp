#include <iostream>
#include "GList.h"

using namespace std;

GList::GList(string s) {
    s = s.substr(1,s.length()-2);
    int max = (int)s.length() - 1;
    
    for (int i=max;i>=0;i--) {
        if (s[i] == ')') {
            int fp = (int)s.find_first_of("(");
            string part = s.substr(fp,s.find_last_of(")")-fp+1);
            add(GList(part));
            i -= part.length() - 1;
        }else{
            add(s[i]);
        }
    }
}

int GList::depth() {
    return depth(first);
}

int GList::depth(GNode *p) {
    int d = 0;
    while (p) {
        if (p->tag) {
            d = max(d,depth(p->dlink));
        }
        p = p->link;
    }
    return d;
}

void GList::add(char value) {
    GNode *p = new GNode();
    p->value = value;
    p->tag = 0;
    p->link = first;
    first = p;
}

void GList::add(GList gl) {
    GNode *p = new GNode();
    p->dlink = gl.first;
    p->tag = 1;
    p->link = first;
    first = p;
}

void GList::print() {
    print(first,0);
    cout << "\n";
}

void GList::print(GNode *p,int in) {
    cout << (in ? ", <" : "<");
    int f = 0;
    while (p) {
        if (p->tag == 1) {
            print(p->dlink,1);
        }else if (p->tag == 0) {
            cout << (f ? ", " : "") << p->value;
        }
        p = p->link;
        f = 1;
    }
    cout << ">";
}
