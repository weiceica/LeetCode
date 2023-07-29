#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        unordered_map<char, int> omp;
        for(int i = 0; i < t.size(); ++i) omp[t[i]]++;
        int l = 0, r = 0, leng = s.length() + 1;
        int curCount = 0, totalCount = omp.size();
        int fff = 0;
        while(r < s.size()){
            char c = s[r];
            if(omp.find(c) != omp.end()){
                mp[c]++;
                if(mp[c] == omp[c]) curCount++;
            }
            while(curCount == totalCount){
                if(r-l+1 < leng){
                    fff = l;
                    leng = r-l+1;
                }
                if(mp.find(s[l]) != mp.end()){
                    mp[s[l]]--;
                    if(mp[s[l]] < omp[s[l]]) curCount--;
                }
                l++;
            }
            r++;
        }
        string sf = "";
        return (leng == s.length()+1) ? sf : s.substr(fff, leng);
    }
};