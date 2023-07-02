	#include<bits/stdc++.h>
    using namespace std;
    
    template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};



BinaryTreeNode<int>* tree(int *input, int si, int ei)
{
    if(si>ei){
        return NULL;
    }
    int mid=(si+ ei)/2;
    
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(input[mid]);
    root->left=tree(input,si,mid-1);
    root->right=tree(input,mid+1,ei);
    
    return root;
    
    
    
    
}


BinaryTreeNode<int>* constructTree(int *input, int n) {
	return tree(input,0,n-1);
}