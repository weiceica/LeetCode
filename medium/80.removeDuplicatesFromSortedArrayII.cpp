#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int r = nums[0]-1;
        int cur = nums[0];
        for(int i = 2; i < nums.size(); ++i){
            if(cur == nums[i] && nums[i] == nums[i-2]){
                cur = nums[i];
                nums[i] = r;
            }
            else if(cur == nums[i] && nums[i-1] == r) nums[i] = r;
            else if(cur != nums[i]) cur = nums[i];
        }
        int ind = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != r) nums[ind++] = nums[i];
        }
        return ind;
    }
};