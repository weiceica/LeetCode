#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end()-k);
        
        reverse(nums.end()-k, nums.end());
        
        reverse(nums.begin(), nums.end());
    }
};