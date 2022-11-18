
// Def of a treenode
  struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

#include <stack>
using namespace std;
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        stack<TreeNode*> s;
        TreeNode* node = root;
        bool traversal = false;
        int preVal;
        
        while(true){
            if(node){
                s.push(node);
                node = node->left;
                continue;
            }
            if(!s.empty()){
                node = s.top();
                s.pop();
                if(!traversal){
                    preVal = node->val;
                    traversal = true;
                }
                else{
                    if(preVal >= node->val) return false;
                    preVal = node->val;
                }
                
                node = node->right;
                continue;
            }
            break;
        }
        return true;   
    }
};