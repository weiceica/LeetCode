#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int> memo(amount+1, 0);
        memo[0] = 0;
        for(int i = 1; i <= amount; ++i){
            memo[i] = numeric_limits<int>::max();
            for(int j = 0; j < coins.size(); ++j)
                if(i - coins[j] >= 0 && memo[i-coins[j]] < numeric_limits<int>::max()) memo[i] = min(memo[i], memo[i-coins[j]] + 1);
        }
        if(memo.back() == numeric_limits<int>::max()) return -1;
        else return memo.back();
    }
};