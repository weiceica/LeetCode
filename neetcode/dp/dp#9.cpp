#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> memo(s.length()+1, false);
        unordered_set<string> hashSet(wordDict.begin(), wordDict.end());
        memo[0] = true;
        for(int i = 1; i < s.size() + 1; ++i){
            for(int j = 0; j < i; ++j){
                if(hashSet.count(s.substr(j, i-j)) && memo[j]){
                    memo[i] = true;
                    break;
                }
            }
        }
        return memo.back();
    }
};