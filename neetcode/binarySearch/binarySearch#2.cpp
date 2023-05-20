#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        if(nums[left] == target) return left;
        if(nums[right] == target) return right;
        while(left < right){
            if(nums[left] == target) return left;
            if(nums[right] == target) return right;
            int mid = (left + right) / 2;
            if(nums[mid] == target) return mid;
            if(nums[left] <= nums[mid]){
                if(target < nums[left]) left = mid + 1;
                else{
                    if(target < nums[mid]) right = mid;
                    else left = mid + 1; 
                }
            }else{
                if(target > nums[right]) right = mid - 1;
                else{
                    if(target > nums[mid]) left = mid;
                    else right = mid - 1;
                }
            }
        }
        return -1;
    }
};