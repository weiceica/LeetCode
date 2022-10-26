#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int current = 0;
        int farthest = 0;
        for(size_t i = 0; i < nums.size() - 1; ++i){
            farthest = max(farthest, nums[i] + (int)i);
            if(i == current){
                if(farthest > i){
                    current = farthest;
                }
                else return false;
            }
        }
        return farthest >= nums.size() - 1;
    }
};