#include <vector>
using namespace std;

class Solution {
public:
    bool hasCycle(vector<vector<int>>& courseGraph, vector<bool>& visited, vector<bool>& pathVisited, int cur){
        visited[cur] = true;
        pathVisited[cur] = true;
        for(auto node:courseGraph[cur]){
            if(!visited[node]){
                if(hasCycle(courseGraph, visited, pathVisited, node)) return true;
            }
            else if(pathVisited[node]) return true;
        }
        pathVisited[cur] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      // basically creating a cycle, and determining whether you can form a cycle
      vector<vector<int>> courseGraph(numCourses);
      for(int i = 0; i < prerequisites.size(); ++i){
        courseGraph[prerequisites[i][1]].push_back(prerequisites[i][0]);
      }
      vector<bool> visited(numCourses,false);
      vector<bool> pathVisited(numCourses, false);
      for(int i = 0; i < numCourses; ++i){
        if(!visited[i]){
          if(hasCycle(courseGraph, visited, pathVisited, i)) return false;
        }
      }
      return true;
    }
};