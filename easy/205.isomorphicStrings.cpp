#include <iostream>;
#include <unordered_map>;
#include <vector>;

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t){
        unordered_map<char, char> umap;
        unordered_map<char, char> vmap;
        for(int i = 0; i < s.length(); ++i){
            if(umap.find(s[i]) == umap.end()){
                umap[s[i]] = t[i];
            }
            if(vmap.find(t[i]) == vmap.end()){
                vmap[t[i]] = s[i];
            }
            if(umap[s[i]] != t[i]) return false;
            if(vmap[t[i]] != s[i]) return false;
        }
        return true;
    }
};
