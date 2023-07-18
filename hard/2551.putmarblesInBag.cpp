#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if(k == 1) return 0; // basecase
        if(k == weights.size()) return 0; // basecase
        vector<int> thingy;
        for(int i = 0; i < weights.size() - 1; ++i){
            thingy.push_back(weights[i] + weights[i+1]);
        }
        sort(thingy.begin(), thingy.end());
        long  mx = 0;
        long  mn = 0;
        for(int i = 0; i < k - 1; ++i){
            mx += thingy[thingy.size()-1-i];
            mn += thingy[i];
        }
        return mx - mn;
    }
};