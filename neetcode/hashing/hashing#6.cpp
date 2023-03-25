#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> vec(nums.size());
        vec[0] = 1;
        for(int i = 1; i < nums.size(); ++i)
            vec[i] = vec[i-1] * nums[i-1];
        int right = 1;
        for(int i = nums.size() - 1; i >= 0; --i){
            vec[i] *= right;
            right *= nums[i];
        }
        return vec;
    }
};