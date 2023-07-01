#include<vector>
using namespace std;
class Solution {
public:
// nums = [1,2,3]
// retval: [[],[1],[1,2],[1,2,3]]
// currentSet: [1,2]
// i = 3

    void dfs(vector<int>&nums, int index, vector<int>& currentSet, vector<vector<int>>& retval){
        retval.push_back(currentSet);

        for(int i = index; i < nums.size(); ++i){
            currentSet.push_back(nums[i]);
            dfs(nums, i+1, currentSet, retval);
            currentSet.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> retval;
        vector<int> currentSet;
        dfs(nums, 0, currentSet, retval);
        return retval;
    }
};