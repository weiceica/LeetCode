#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        priority_queue<int> pq;
        int time = 0;
        for(int i = 0; i < tasks.size(); ++i) freq[tasks[i] - 'A']++;
        for(int i = 0; i < freq.size(); ++i){
            if(freq[i] != 0){
                pq.push(freq[i]);
            }
        }
        queue<pair<int, int>> q;
        while(!pq.empty() || !q.empty()){
            time++;
            if(!pq.empty()){
                int current = pq.top();
                if(current - 1 != 0) q.push({current-1, time+n});
                pq.pop();
            }
            if(!q.empty() && time == q.front().second){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};