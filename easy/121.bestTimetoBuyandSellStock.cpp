#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        vector<int> memo;
        memo.resize(prices.size());
        memo[0] = -100000;
        for(size_t i = 1; i < memo.size(); ++i){
            if(prices[i] - min <= memo[i-1]) memo[i] = memo[i-1];
            else memo[i] = prices[i] - min;
            if(prices[i] < min) min = prices[i];
        }
        if(memo.back() < 0) return 0;
        return memo.back();
    }
};