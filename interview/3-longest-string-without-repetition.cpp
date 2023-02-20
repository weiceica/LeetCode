#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // basecase
        if(s.length() == 1) return 1;
        unordered_set<char> c;
        int l = 0;
        int result = 0;
        c.insert(s[0]);
        for(int i = 1; i < s.length(); ++i){
            while(c.find(s[i]) != c.end()){
                c.erase(s[l]);
                l++;
            }
            c.insert(s[i]);
            result = max(result, i - l + 1);
        }
        return result;
    }
};