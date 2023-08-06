#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> umap;
        for(int i = 0; i < magazine.size(); ++i){
        umap[magazine[i]]++;
        }
        for(int i = 0; i < ransomNote.size(); ++i){
            if(--umap[ransomNote[i]] < 0) return false;
        }
        return true;
    }
};