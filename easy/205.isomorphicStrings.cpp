#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t){
        unordered_map<char, char> umap;
        unordered_set<char> uset;
        for(int i = 0; i < s.size(); ++i){
            if(umap.find(s[i]) == umap.end()){
                if(uset.count(t[i]) != 0) return false;
                uset.insert(t[i]);
                umap[s[i]] = t[i];
            }
            else{
                if(umap[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};
