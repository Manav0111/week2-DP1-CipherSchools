#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int ans;
    TreeNode* f(TreeNode* root,int &k)
    {
        if(root==NULL)
            return NULL;
     TreeNode* l=f(root->left,k);
        k--;
        if(k==0)
        {
            ans=root->val;
            return root;
        }
        TreeNode* r=f(root->right,k);
        return root;
    }
    int kthSmallest(TreeNode* root, int k) {
        ans=root->val;
        TreeNode* r=f(root,k);
        return ans;
    }
};