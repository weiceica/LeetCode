#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uset;
        for(int i = 0; i < nums.size(); ++i){
            if(uset.find(nums[i]) != uset.end()) return true;
            uset.insert(nums[i]);
        }
        return false;
    }
};