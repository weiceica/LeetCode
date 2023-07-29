#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uset;
        int l = 0;
        int curSum = 0;
        for(int r = 0; r < s.length(); ++r){
            while(uset.count(s[r]) != 0 && l < r){
                uset.erase(s[l++]);
            }
            uset.insert(s[r]);
            curSum = max(r-l+1, curSum);
        }
        return curSum;
    }
};