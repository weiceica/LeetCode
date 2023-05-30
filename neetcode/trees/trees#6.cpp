#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> cur;
            int s = q.size();
            for(int i = 0; i < s; ++i){
                TreeNode* temp = q.front();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                cur.push_back(temp->val);
                q.pop();
            }
            res.push_back(cur);
        }
        return res;
    }
};