#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // we do two loops? loop 1- first x - last loop2- last x - first
        int prev = nums[0];
        if(nums.size() <= 3){
            for(size_t i = 0; i < nums.size(); ++i){
                prev = max(prev, nums[i]);
            }
            return prev;
        }
        int cur = nums[1];
        for(size_t i = 2; i < nums.size() - 1; ++i){
            int temp = cur;
            cur = max(nums[i] + prev, cur);
            prev = max(prev, temp);
        }
        int x = cur;
        cur = nums[2];
        prev = nums[1];
        for(size_t i = 3; i < nums.size(); ++i){
            int temp = cur;
            cur = max(nums[i] + prev, cur);
            prev = max(prev, temp);
        }
        return max(x, cur);
    }
};