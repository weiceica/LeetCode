#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int ret = target + 1;
        int sum = 0;
        for(int r = 0; r < nums.size(); ++r){
            sum += nums[r];
            while(sum >= target && r < nums.size()){
                ret = min(ret, r-l+1);
                sum -= nums[l++];
            }
        }
        return ret == target + 1 ? 0 : ret;
    }
};