#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> nums(temperatures.size(), 0);
        stack<pair<int, int>> s;
        for(int i = 0; i < temperatures.size(); ++i){
            while(!s.empty() && temperatures[i] > s.top().first){
                pair<int, int> p = s.top();
                s.pop();
                nums[p.second] = i-p.second;
                cout << p.second << endl;
            }
            s.push({temperatures[i], i});
        }
        return nums;
    }
};