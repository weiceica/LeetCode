#include <algorithm>
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
    bool isValid(TreeNode* root, double left, double right){
        if(!root) return true;
        else if(root->val >= right || root->val <= left) return false;
        return isValid(root->left, left, root->val) && isValid(root->right, root->val, right);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root, -numeric_limits<double>::infinity(), numeric_limits<double>::infinity());
    }
};