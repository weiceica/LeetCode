#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;
        for(int i = 0; i < s.length(); ++i){
            smap[s[i]]++;
            tmap[t[i]]++;
        }
        if(smap.size() != tmap.size()) return false;
        for(int i = 0; i < s.length(); ++i){
            if(smap[s[i]] != tmap[s[i]]) return false;
        }
        return true;
    }
};