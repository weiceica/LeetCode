#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>> q;
        int maxArea = 0;
        for(int y = 0; y < grid.size(); ++y){
            for(int x = 0; x < grid[0].size(); ++x){
                if(visited[y][x]) continue;
                visited[y][x] = true;
                if(grid[y][x] == 0) continue;
                q.push({y,x});
                int curArea = 1;
                while(!q.empty()){
                    int yy = q.front().first;
                    int xx = q.front().second;
                    q.pop();
                    if(yy+1<grid.size() && !visited[yy+1][xx] && grid[yy+1][xx] == 1){
                        q.push({yy+1, xx});
                        visited[yy+1][xx] = true;
                        curArea++;
                    }
                    if(yy-1>=0 && !visited[yy-1][xx] && grid[yy-1][xx] == 1){
                        q.push({yy-1, xx});
                        visited[yy-1][xx] = true;
                        curArea++;
                    }
                    if(xx+1<grid[0].size() && !visited[yy][xx+1] && grid[yy][xx+1] == 1){
                        q.push({yy, xx+1});
                        visited[yy][xx+1] = true;
                        curArea++;
                    }
                    if(xx-1>=0 && !visited[yy][xx-1] && grid[yy][xx-1] == 1){
                        q.push({yy, xx-1});
                        visited[yy][xx-1] = true;
                        curArea++;
                    }
                    
                }
                if(curArea > maxArea) maxArea = curArea;
            }
        }
        return maxArea;
    }
};