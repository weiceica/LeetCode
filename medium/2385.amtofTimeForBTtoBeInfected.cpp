#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void treeToGraph(TreeNode* root, unordered_map<int, vector<int>>& adjList){
        if(adjList.find(root->val) == adjList.end())
            adjList[root->val] = vector<int>();
        if(root->left){
            adjList[root->val].push_back(root->left->val);
            if(adjList.find(root->left->val) == adjList.end())
                adjList[root->left->val] = vector<int>();
            adjList[root->left->val].push_back(root->val);
            treeToGraph(root->left, adjList);
        }
        if(root->right){
            adjList[root->val].push_back(root->right->val);
            if(adjList.find(root->right->val) == adjList.end())
                adjList[root->right->val] = vector<int>();
            adjList[root->right->val].push_back(root->val);
            treeToGraph(root->right, adjList);
        }
    }

    int bfs(int start, unordered_map<int, vector<int>>& adjList){
        queue<int> q;
        unordered_set<int> v;
        q.push(start);
        v.insert(start);
        int ret = -1;
        for(int i = 0; i < adjList[start].size(); ++i) cout << adjList[start][i] << endl;
        while(!q.empty()){
            int cq = q.size();
            for(int i = 0; i < cq; ++i){
                int cur = q.front();
                q.pop();
                for(int i = 0; i < adjList[cur].size(); ++i){
                    if(v.count(adjList[cur][i]) == 0){
                        q.push(adjList[cur][i]);
                        v.insert(adjList[cur][i]);
                    }
                }
            }
            ret++;
        }
        return ret;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adjList;
        treeToGraph(root, adjList);
        return bfs(start, adjList);
    }
};