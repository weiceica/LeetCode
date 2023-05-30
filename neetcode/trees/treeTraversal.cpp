/*
    This file is created because I really struggled with trees.... This is to review the basics of trees
    I have included the recursive, and iterative defintions of tree traversal.
    Refer to the first questions of trees to understand them.
*/
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

class Tree {
    private: 
    // definition of TreeNode
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    public:
    // Recursive inorder:
    void recursiveInorder(TreeNode* root){
        if(!root) return;
        recursiveInorder(root->left);
        cout << root->val << endl;
        recursiveInorder(root->right);
    }

    // Iterative inorder:
    void iterativeInorder(TreeNode* root){
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur || !s.empty()){
            while(cur){
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            cout << cur->val << endl;
            cur = cur->right;
        }
        return;
    }

    // Recursive preorder:
    void recursivePreorder(TreeNode* root){
        if(!root) return;
        cout << root->val << endl;
        recursivePreorder(root->left);
        recursivePreorder(root->right);
    }

    // Iterative preorder:
    void iterativePreorder(TreeNode* root){
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* cur = s.top();
            s.pop();
            cout << cur->val << endl;
            if(cur->right) s.push(cur->right);
            if(cur->left) s.push(cur->left);
        }
        return;
    }

    // Recursive postorder:
    void recursivePostorder(TreeNode* root){
        if(!root) return;
        recursivePostorder(root->left);
        recursivePostorder(root->right);
        cout << root->val << endl;
    }

    // Iterative postorder:
    vector<int> iterativePostorder(TreeNode* root){
        stack<TreeNode*> s;
        TreeNode* cur = root;
        TreeNode* lv = nullptr;
        while(!s.empty() || cur){
            if(cur){
                s.push(cur);
                cur = cur->left;
            }
            else{
                TreeNode* tn = s.top();
                if (tn->right && tn->right != lv) {
                    cur= tn->right;
                } else {
                    cout << tn->val << " ";
                    s.pop();
                    lv = tn;
                }
            }
        }
    }
};