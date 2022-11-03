#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, 0));
        memo[0][0] = 1;
        for(size_t i = 1; i < n; ++i){
            memo[0][i] = 1;
        }
        for(size_t i = 1; i < m; ++i){
            memo[i][0] = 1;
        }
        for(size_t i = 1; i < m; ++i){
            for(size_t j = 1; j < n; ++j){
                memo[i][j] = memo[i-1][j] + memo[i][j-1];
            }
        }
        return memo[m-1][n-1];
    }
};