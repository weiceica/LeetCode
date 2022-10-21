#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> retList;
        retList.resize(nums.size());
        int count = 0;
        for(size_t i = 0; i < nums.size(); ++i){
            count += nums[i];
            retList[i] = count;
        }
        return retList;
    }
};