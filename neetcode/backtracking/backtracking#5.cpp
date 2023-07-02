#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void magicalshit(vector<vector<int>>& retval, vector<int>& currentset, vector<int>& candidates, int target, int pos){
        if(target == 0) retval.push_back(currentset);
        if(target < 0) return;
        for(int i = pos; i < candidates.size(); ++i){
            if(i != pos && candidates[i] == candidates[i-1]) continue;
            currentset.push_back(candidates[i]);
            magicalshit(retval, currentset, candidates, target-candidates[i], i+1);
            currentset.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> retval;
        vector<int> currentset;
        sort(candidates.begin(), candidates.end());
        magicalshit(retval, currentset, candidates, target, 0);
        return retval;
    }
};