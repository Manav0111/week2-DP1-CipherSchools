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

    int height(TreeNode* root)
    {
        if(root==NULL)
        return 0;

        return 1+max(height(root->left),height(root->right));
    }


    bool helper(TreeNode *root)
    {
        if(root==NULL)
        return true;

        int lh=height(root->left);
        int rh=height(root->right);

        int diff=abs(lh-rh);
        if(diff>1)
        {
            return false;
        }
        else
        {
            return diff<=1 && helper(root->left) && helper(root->right);
        }
    }


    bool isBalanced(TreeNode* root) {
        return helper(root);
    }
};
