#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < points.size(); ++i){
            double distance = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pq.push({distance*-1, i});
        }
        vector<vector<int>> retval;
        for(int i = 0; i < k; ++i){
            pair<int, int> val = pq.top();
            pq.pop();
            retval.push_back(points[val.second]);
        }
        return retval;
    }
};