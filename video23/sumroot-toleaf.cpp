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
void solve(TreeNode* root, int& sum,int num){
     if(!root) return;
    num = num*10 + root->val;
    if(root->left==NULL && root->right==NULL) {         //base case
     sum += num;
     return;
    }  
   

    
     solve(root->left, sum,num);
     
     solve(root->right,sum,num);

 
}
    int sumNumbers(TreeNode* root) {
        int sum=0;
        int num=0;
        solve(root,sum,num);
        return sum;
    }
};