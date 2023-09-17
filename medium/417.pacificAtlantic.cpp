#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int row, int col){
        if(visited[row][col]) return;
        visited[row][col] = true;
        if(row > 0 && heights[row][col] <= heights[row-1][col]) dfs(heights, visited, row-1, col);
        if(row < heights.size() - 1 && heights[row][col] <= heights[row+1][col]) dfs(heights, visited, row+1, col);
        if(col > 0 && heights[row][col] <= heights[row][col-1]) dfs(heights, visited, row, col-1);
        if(col < heights[0].size() - 1 && heights[row][col] <= heights[row][col+1]) dfs(heights, visited, row, col+1);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), 0));
        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), 0));
        for(int row = 0; row < heights.size(); ++row){
            dfs(heights, atlantic, row, heights[0].size() - 1);
            dfs(heights, pacific, row, 0);
        }
        for(int col = 0; col < heights[0].size(); ++col){
            dfs(heights, atlantic, heights.size() - 1, col);
            dfs(heights, pacific, 0, col);
        }
        for(int i = 0; i < heights.size(); ++i){
            for(int j = 0; j < heights[0].size(); ++j){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back(vector<int>{i,j});
                }
            }
        }
        return res;
    }
};