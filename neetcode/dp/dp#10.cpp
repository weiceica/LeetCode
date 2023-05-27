#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> memo(nums.size(), 1);
        memo.back() = 1;
        for(int i = nums.size() - 2; i >= 0; --i){
            for(int j = i + 1; j < nums.size(); ++j){
                if(nums[i] < nums[j]){
                    memo[i] = max(memo[i], memo[j] + 1);
                }
            }
        }
        return *max_element(memo.begin(), memo.end());
    }
};