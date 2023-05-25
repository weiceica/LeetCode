#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = nums[0], curMin = nums[0], ans = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            int temp = curMax;
            curMax = max({curMax * nums[i], nums[i], curMin * nums[i]});
            curMin = min({temp * nums[i], nums[i], curMin * nums[i]});
            ans = max(ans, curMax);
        }
        return ans;
    }
};