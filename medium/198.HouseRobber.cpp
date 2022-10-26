#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), 0);
        if(nums.size() == 1) return nums[0];
        memo[0] = nums[0];
        memo[1] = max(nums[0], nums[1]);
        for(size_t i = 2; i < nums.size(); ++i){
            if(memo[i-1] == memo[i-2]) memo[i] = memo[i-1] + nums[i];
            else memo[i] = max(memo[i-1], memo[i-2]+nums[i]);
        }
        return memo.back();
    }
};