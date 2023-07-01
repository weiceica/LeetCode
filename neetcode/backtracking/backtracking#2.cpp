#include <vector>
using namespace std;
class Solution {
public:
    void magicalShit(vector<vector<int>>& retval, vector<int>& candidates, int target, int pos, vector<int>& currentSet){
        if(target == 0) retval.push_back(currentSet);
        if(target < 0) return;
        for(int i = pos; i < candidates.size(); ++i){
            currentSet.push_back(candidates[i]);
            magicalShit(retval, candidates, target - candidates[i], i, currentSet);
            currentSet.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> retval;
        vector<int> currentSet;
        magicalShit(retval, candidates, target, 0, currentSet);
        return retval;
    }
};