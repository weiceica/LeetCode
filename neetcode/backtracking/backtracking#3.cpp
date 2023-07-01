#include <vector>
using namespace std;
class Solution {
public:
    void magicalshit(vector<vector<int>>& retval, vector<int>& currentset, vector<int>& nums, vector<bool>& included){
        if(currentset.size() == nums.size()){
            retval.push_back(currentset);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(!included[i]){
                currentset.push_back(nums[i]);
                included[i] = true;
                magicalshit(retval, currentset, nums, included);
                included[i] = false;
                currentset.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> retval;
        vector<int> currentset;
        vector<bool> included(nums.size(), false);
        magicalshit(retval, currentset, nums, included);
        return retval;
    }
};