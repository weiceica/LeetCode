#include <algorithm>
#include <unordered_map>
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
    void dfs(TreeNode* r, unordered_map<int, int>& umap, int& mf){
        if(r->left) dfs(r->left, umap, mf);
        if(r->right) dfs(r->right, umap, mf);
        if(r->left) r->val += r->left->val;
        if(r->right) r->val += r->right->val;
        mf = max(mf, ++umap[r->val]);
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> retval;
        unordered_map<int, int> umap;
        int mf = 0;
        dfs(root, umap, mf);
        for(auto u:umap){
            if(u.second == mf) retval.push_back(u.first);
        }
        return retval;
    }
};