#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> memo = obstacleGrid;
        if(memo[0][0] == 1) return 0;
        memo[0][0] = 1;
        bool notReachableR = false;
        bool notReachableC = false;
        for(size_t i = 1; i < memo[0].size(); ++i){
            if(memo[0][i] == 1) notReachableR = true;
            if(!notReachableR) memo[0][i] = 1;
            else memo[0][i] = -1;
        }
        for(size_t i = 1; i < memo.size(); ++i){
            if(memo[i][0] == 1) notReachableC = true;
            if(!notReachableC) memo[i][0] = 1;
            else memo[i][0] = -1;
        }
        for(size_t i = 1; i < memo.size(); ++i){
            for(size_t j = 1; j < memo[0].size(); j++){
                if(memo[i][j] == 1) memo[i][j] = -1;
                if(memo[i][j] != -1){
                    if(memo[i][j-1] == -1 && memo[i-1][j] != -1) memo[i][j] = memo[i-1][j];
                    else if(memo[i][j-1] != -1 && memo[i-1][j] == -1) memo[i][j] = memo[i][j-1];
                    else if(memo[i][j-1] != -1 && memo[i-1][j] != -1) memo[i][j] = memo[i-1][j] + memo[i][j-1];
                }
            }
        }
        if(memo[memo.size()-1][memo[0].size()-1] == -1) return 0;
        return memo[memo.size()-1][memo[0].size()-1];
    }
};