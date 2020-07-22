/*

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

*/

//Code:

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> nextlevel,q;
        bool lefttoright=true;
        vector<vector<int>> ans;
        if(root==NULL)
        {
            return ans;
        }
        vector<int> temp;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* k=q.top();
            q.pop();
            if(lefttoright)
            {
                
                if(k->left) 
                {
                    nextlevel.push(k->left);
                }
                 if(k->right)
                 {
                     nextlevel.push(k->right);
                 }
                
            }
            else
            {
                if(k->right)
                 {
                     nextlevel.push(k->right);
                 }
               if(k->left) 
                {
                    nextlevel.push(k->left);
                }
            }
            if(k)
            {
                temp.push_back(k->val);
            }
            if(q.empty())
            {
                ans.push_back(temp);
                temp.clear();
                lefttoright=!lefttoright;
                swap(nextlevel,q);
            }
            
        }
        return ans;
    }
};
