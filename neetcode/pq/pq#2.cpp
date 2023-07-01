#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1) return stones.front();
        priority_queue<int> pq;
        for(int i = 0; i < stones.size(); ++i) pq.push(stones[i]);
        while(pq.size() >= 2){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(x != y) pq.push(x - y);
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};