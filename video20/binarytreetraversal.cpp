#include<bits/stdc++.h>
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

void inorder(TreeNode *root, vector<int> &result)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}

vector<int> inorder(TreeNode *root)
{
    vector<int> result;
    inorder(root, result);
    return result;
}

vector<int> preorder(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> back;
    auto cur = root;
    while (cur || !back.empty())
    {
        if (cur)
        {
            res.push_back(cur->val);
            if (cur->right)
                back.push(cur->right);
            cur = cur->left;
        }
        else
        {
            cur = back.top();
            back.pop();
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