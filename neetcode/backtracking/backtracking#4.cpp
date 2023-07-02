#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void magicalshit(vector<vector<int>>& retval, vector<int>& currentset, vector<int>& nums, int pos){  
        retval.push_back(currentset);
        for(int i = pos; i < nums.size(); ++i){
            if(i != pos && nums[i] == nums[i-1]) continue;
            currentset.push_back(nums[i]);
            magicalshit(retval, currentset, nums, i+1);
            currentset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> retval;
        vector<int> currentset;
        magicalshit(retval, currentset, nums, 0);
        return retval;
    }
};