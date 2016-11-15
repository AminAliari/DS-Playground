#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, const char * argv[]) {
    
    char sign = 0;
    int input = 0, inputCount = 0,rcount = 0;
    string pattern = "",number = "";
    
    cin >> inputCount;
    
    int *set = new int[inputCount];
    int *result = new int[inputCount];
    
    fill_n(set, inputCount, -1);
    
    for (int i=0;i<inputCount;i++) {
        
        cin >> sign;
        
        switch (sign) {
            case '+':
                cin >> input;
                set[i] = input;
                break;
                
            case '-':
                cin >> input;
                for (int r = 0; r<i;r++) {
                    if (set[r] == input) {
                        set[r] = -1;
                        break;
                    }
                }
                break;
                
            case '?':
                cin >> pattern;
                
                bool match;
                int n = 0, len = 0,plen = 0, sub = 0;
                
                for (int q=0;q<i;q++) {
                    if (set[q] == -1) continue;
                    
                    match = true;
                    number = to_string(set[q]);
                    len = (int)number.length();
                    plen = (int)pattern.length();
                    sub = len - plen;
                    
                    for (int r=1;r<=plen;r++) {
                        if (sub >= 0) {
                            if ((pattern[plen-r] != '0' || number[len-r] % 2 != 0) && (pattern[plen-r] != '1' || number[len-r] % 2 == 0)) {
                                match = false;
                                break;
                            }
                        }else{
                            if (r <= len) {
                                if ((pattern[plen-r] != '0' || number[len-r] % 2 != 0) && (pattern[plen-r] != '1' || number[len-r] % 2 == 0)) {
                                    match = false;
                                    break;
                                }
                            }else if (pattern[plen-r] != '0') {
                                match = false;
                                break;
                            }
                        }
                    }
                    if (match) {
                        n++;
                    }
                }
                result[rcount] = n;
                rcount++;
                break;
        }
    }
    for (int i=0;i<rcount;i++) {
        cout << result[i] << endl;
    }
    cout << endl;
    return 0;
}
