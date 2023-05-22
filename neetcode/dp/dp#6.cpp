#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> memo(n+1);
        memo[n] = 1;
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == '0') memo[i] = 0;
            else {
                memo[i] = memo[i+1];
                if(i < n-1 && (s[i] == '1' || s[i] == '2' && s[i+1] < '7')) memo[i] += memo[i+2];
            }
        }
        return s.empty()? 0 : memo[0];  
    }
};