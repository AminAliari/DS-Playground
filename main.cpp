#include <iostream>
#include "GList.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    GList gl("(a(bc(de)f)(g(h(ij))))");

    gl.print();
    cout << gl.depth() << "\n";
    
    return 0;
}
