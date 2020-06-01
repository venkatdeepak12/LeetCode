/*

Question :

Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9

Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1


Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), 
        but you can’t invert a binary tree on a whiteboard so f*** off.
        
 */
 
 
 //Code:
 
 class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
        {
            return root;
        }
        root->left=invertTree(root->left);
        root->right=invertTree(root->right);
        TreeNode *temp;
        if(root->left!=NULL and root->right!=NULL)
        {
            temp=root->left;
            root->left=root->right;
            root->right=temp;
            return root;
        }
        if(root->left==NULL and root->right!=NULL)
        {
            root->left=root->right;
            root->right=NULL;
            return root;
        }
        if(root->right==NULL and root->left!=NULL)
        {
            root->right=root->left;
            root->left=NULL;
            return root;
        }
        
        return root;
        
    }
};
