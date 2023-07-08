#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>>q;
        int numIslands = 0;
        for(int y = 0; y < grid.size(); ++y){
            for(int x = 0; x < grid[0].size(); ++x){
                if(visited[y][x]) continue;
                visited[y][x] = true;
                if(grid[y][x] == '1'){
                    q.push({y,x});
                    while(!q.empty()){
                        int xVal = q.front().second;
                        int yVal = q.front().first;
                        q.pop();
                        if(yVal+1<grid.size() && grid[yVal+1][xVal] == '1' && !visited[yVal+1][xVal]){
                            q.push({yVal+1,xVal});
                            visited[yVal+1][xVal] = true;
                        }
                        if(xVal+1<grid[0].size() && !visited[yVal][xVal+1] && grid[yVal][xVal+1] == '1'){
                            q.push({yVal, xVal+1});
                            visited[yVal][xVal+1] = true;
                        }
                        if(yVal-1>=0 && !visited[yVal-1][xVal] && grid[yVal-1][xVal] == '1'){
                            q.push({yVal-1,xVal});
                            visited[yVal-1][xVal] = true;
                        }
                        if(xVal-1>=0 && !visited[yVal][xVal-1] && grid[yVal][xVal-1] == '1'){
                            q.push({yVal, xVal-1});
                            visited[yVal][xVal-1] = true;
                        }
                    }
                    numIslands += 1;
                }
            }
        }
        return numIslands;
    }
};