#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> out;
        unordered_map<int, int> h;
        for(int i = 0; i < nums.size(); ++i){
            int second_int = target - nums[i]; 
            if(h.find(second_int) != h.end()){
                out.push_back(i);
                out.push_back(h.find(second_int)->second);
                break;
            }
            else h[nums[i]] = i;
        }
        return out;
    }
};