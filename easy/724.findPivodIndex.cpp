#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0; 
        for(size_t i = 0; i < nums.size(); ++i){
            sum += nums[i];
        }
        int sumL = 0;
        int sumR = 0;
        vector<int> sumTableL;
        vector<int> sumTableR;
        sumTableL.resize(nums.size());
        sumTableR.resize(nums.size());
        for(size_t i = 0; i < nums.size(); ++i){
            sumL += nums[i];
            sumR = sum - sumL;
            sumTableL[i] = sumL - nums[i];
            sumTableR[i] = sumR;
        }
        int retVal = -1;
        for(size_t i = 0; i < nums.size(); ++i){
            if(sumTableL[i] == sumTableR[i]){
                retVal = i;
                break;
            }
        }
        return retVal;
    }
};