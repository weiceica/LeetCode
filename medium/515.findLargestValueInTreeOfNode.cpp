#include <algorithm>
#include <queue>
#include <vector>
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
    vector<int> largestValues(TreeNode* root) {
        // bfs shit 
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int curSize = q.size();
            int r = INT_MIN;
            for(int i = 0; i < curSize; ++i){
                TreeNode* cur = q.front();
                q.pop();
                r = max(r, cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            res.push_back(r);
        }

        return res;
    }
};