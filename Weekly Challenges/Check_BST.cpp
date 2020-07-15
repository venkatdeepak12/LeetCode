/*

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
   
*/
   
//Code:
   
   
class Solution {
public:
    bool check(TreeNode *root1,TreeNode* root2)
    {
        if(root1==NULL and root2==NULL) return  true;
        if(root1 and root2 and root1->val==root2->val)
        {
            return check(root1->left,root2->right)*check(root1->right,root2->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
       return check(root,root);
    }
};
