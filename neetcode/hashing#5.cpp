#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for(size_t i = 0; i < nums.size(); ++i){
            umap[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto u : umap){
            pq.push({u.second, u.first});
            if(pq.size() > k) pq.pop();
        }
        vector<int> retval;
        while(!pq.empty()){
            retval.push_back(pq.top().second);
            pq.pop();
        }
        reverse(retval.begin(), retval.end());
        return retval;    
    }
};