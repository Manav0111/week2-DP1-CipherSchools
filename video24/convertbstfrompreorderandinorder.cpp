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


BinaryTreeNode<int>* helperbuilt(int preorder[],int prestart,int preend, int inorder[],int inorderstart, int inorderend)
{ 
    if( inorderstart>inorderend)
        return NULL;
    
    int rootdata=preorder[prestart];
    int rootindex=-1;
    
    for(int i=inorderstart; i<=inorderend; i++)
    {
			if(inorder[i]==rootdata)
            {
					rootindex=i;
                	break;
            }
    }
    
    int lis=inorderstart;
    int lie=rootindex-1;
    
    int lps=prestart+1;
    int lpe=lie-lis+lps;
        
    int rps=lpe+1;
    int rpe=preend;
        
    int ris=rootindex+1;
    int rie=inorderend;
    
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootdata);
    root->left=helperbuilt(preorder,lps,lpe,inorder,lis,lie);
    root->right=helperbuilt(preorder,rps,rpe,inorder,ris,rie);
    
    return root;
    
    
}
BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    
    return helperbuilt(preorder,0,preLength-1,inorder,0,inLength-1);
}