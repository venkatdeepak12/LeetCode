/*

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
  
  
*/

//Code:

class Solution {
public:
    int search(vector<int> &a, int x)
    {
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==x) return i;
        }
        return -1;
    }
    TreeNode* bintree(vector<int> &inorder,int in,int n,vector<int>& postorder,int ps,int m)
    {
       if(in>n || ps>m) return nullptr;
        TreeNode *root=new TreeNode(postorder[m]);
        int pos=search(inorder,postorder[m]);
        root->left=bintree(inorder,in,pos-1,postorder,ps,ps+pos-in-1);
        root->right=bintree(inorder,pos+1,n,postorder,ps+pos-in,m-1);
        return root;
        
    }
     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
     {
        return bintree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
     }
};
