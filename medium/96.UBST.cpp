class Solution {
public:
    int numTrees(int n) {
        vector<int> memo(n+1);
        memo[0] = 1;
        memo[1] = 1;
        for(size_t i = 2; i <= n; ++i){
            for(size_t j = 1; j <= i; ++j){
                memo[i] = memo[i] + memo[j-1] * memo[i - j];
            }
        }
        return memo[n];
    }
};