#include<bits/stdc++.h>
using namespace std;

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

vector<int> inorder(TreeNode *root)
{
    vector<int> res;
    if (!root)
        return res;
    stack<TreeNode *> inorder;
    while (root)
    {
        inorder.push(root);
        root = root->left;
    }

    while (!inorder.empty())
    {
        TreeNode *tmpN = inorder.top();
        inorder.pop();
        res.push_back(tmpN->val);

        TreeNode *right = tmpN->right;
        while (right)
        {
            inorder.push(right);
            right = right->left;
        }
    }
    return res;
}

TreeNode *Insert(TreeNode *root, int data)
{
    if (root == NULL)
    {
        root = new TreeNode();
        root->val = data;
        root->left = root->right = NULL;
    }
    else if (data <= root->val)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}