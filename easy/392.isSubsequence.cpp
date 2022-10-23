#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        if(s.size() == 0) return true;
        for(; i < t.size(); ++i){
            if(s[j] == t[i]){
                j++;
            }
            if(j == s.size()) return true;
        }
        return false;
    }
};