struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
private:
    int res = 0;
public:
    void dfs(TreeNode* r, int& targetSum, int& res, long long& cur){
        cur += r->val;
        if(cur == targetSum) res++;
        if(r->left){
            dfs(r->left, targetSum, res, cur);
            cur -= r->left->val;
        }
        if(r->right){
            dfs(r->right, targetSum, res, cur);
            cur -= r->right->val;
        }
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        long long cur = 0;
        dfs(root, targetSum, res, cur);
        if(root->left) pathSum(root->left,targetSum);
        if(root->right) pathSum(root->right, targetSum);
        return res;
    }
};