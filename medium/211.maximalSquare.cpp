#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> memo(matrix.size()+1, vector<int>(matrix[0].size() + 1, 0));
        for(int i = matrix.size() - 1; i >= 0; --i){
            for(int j = matrix[0].size() - 1; j >= 0; --j){
                if(matrix[i][j] == '1') memo[i][j] = min(min(memo[i+1][j], memo[i][j+1]), memo[i+1][j+1]) + 1;
            }
        }
        int retval = memo[0][0];
        for(int i = 0; i < memo.size(); ++i){
            for(int j = 0; j < memo[0].size(); ++j){
                retval = max(retval, memo[i][j]);
            }
        }
        return retval * retval;
    }
};