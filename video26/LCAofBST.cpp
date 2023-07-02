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
	TreeNode* lowestCommonAncestor(TreeNode* curr, TreeNode* p, TreeNode* q) {
		if(!curr || curr==p || curr==q) return curr;
		TreeNode* l=lowestCommonAncestor(curr->left,p,q);
		TreeNode* r=lowestCommonAncestor(curr->right,p,q);
		if(!l) return r;
		else if(!r) return l;
		else return curr;
	}
};