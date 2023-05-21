#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int prev = nums[0];
        int cur = nums[1];
        if(nums.size() == 2) return max(prev, cur);
        for(size_t i = 2; i < nums.size(); ++i){
            int temp = cur;
            cur = max(nums[i] + prev, cur);
            prev = max(temp, prev);
        }
        return cur;
    }
};