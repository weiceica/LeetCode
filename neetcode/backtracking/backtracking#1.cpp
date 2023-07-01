#include<vector>
using namespace std;
class Solution {
public:
/*
nums = [1,2,3]
[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

*/
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> curSet;
        subsets.push_back(curSet);
        for (int num : nums) {
            int currentSubsetCount = subsets.size();
            for (int i = 0; i < currentSubsetCount; ++i) {
                vector<int> newSubset = subsets[i];
                newSubset.push_back(num);
                subsets.push_back(newSubset);
            }
        }
        return subsets;
    }
};