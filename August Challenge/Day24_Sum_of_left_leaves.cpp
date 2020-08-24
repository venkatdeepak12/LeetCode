/*

Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

*/

//Code:

class Solution {
public:
    int sum=0;
    void check(TreeNode* root)
    {
        if(!root) return ;
        if(root->left)
        {
            if(root->left->left==NULL and root->left->right==NULL)
            {
                sum+=root->left->val;
            }
        }
        check(root->left);
        check(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        sum=0;
        check(root);
        return sum;
    }
};
