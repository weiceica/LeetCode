#include <vector>
using namespace std;

class Solution {
public:
    // int findDuplicate(vector<int>& nums) {
    //     // case 2
    //     if(nums.size() == 2) return nums[0];
    //     nums.push_back(-1);
    //     nums.push_back(-1);
    //     // rest of the cases
    //     int* slow = &nums[0];
    //     int* fast = &nums[0];

    //     slow++;
    //     fast += 2;

    //     while(*slow != *fast){
    //         if(*(slow + 1) == -1 && *slow != *(fast + 2)){
    //             slow = &nums[0];
    //             fast = &nums[1];
    //             continue;
    //         }
    //         else slow++;
    //         if(*(fast + 1) == -1) fast = &nums[1];
    //         else if(*(fast + 2) == -1) fast = &nums[0];
    //         else{
    //             fast++;
    //             fast++;
    //         }
    //     }


    //     return *slow;
    // }

    int findDuplicate(vector<int>& nums){
        
    }

};