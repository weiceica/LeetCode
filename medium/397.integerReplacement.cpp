#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
private: 
    int k = 0;
public:
    int integerReplacement(int n) {
        cout << k << " " << n << endl;
        if(n == 1) return k;
        if(n == 3){
            k += 2;
            return k;
        }
        if(n == INT_MAX) return 32;
        if(n % 2 == 0){
            ++k;
            integerReplacement(n/2);
        }
        else if((n+1) % 4 == 0){
            ++k;
            integerReplacement(n+1);
        }
        else{
            ++k;
            integerReplacement(n-1);
        }
        return k;
    }
};