/*

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]


*/

//Code:

class Solution {
public:
    
   
    void dfs(TreeNode* root,int level,vector<vector<int>>& a){
        if(!root) return; 
        if(level == a.size()) a.push_back({});  
        a[level].push_back(root->val);  
        dfs(root->left,level+1,a);  
        dfs(root->right,level+1,a);  
    }
 
   
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};  
        vector<vector<int>>a;  
        dfs(root,0,a);  
        reverse(a.begin(),a.end()); 
        return a;
    }
};
