#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        for(int i = 1; i < nums.size(); ++i){
            nums[i] = max(nums[i-1], nums[i] + i);
        }
        int j = 0;
        while(j < nums.size() - 1){
            j = nums[j];
            count++;
        }
        return count;
    }
};