#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // fixed window approach
        if(s1.size() > s2.size()) return false;
        unordered_map<char, int> s1map, window;
        for(int i = 0; i < s1.size(); ++i){
            s1map[s1[i]]++;
            window[s2[i]]++;
        }
        if(s1map == window) return true;
        int left = 0;
        for(int i = s1.size(); i < s2.size(); ++i){
            if(window[s2[left]] == 1) window.erase(s2[left]);
            else window[s2[left]]--;
            window[s2[i]]++;
            left++;
            if(window == s1map) return true;
        }
        return false;
    }
};