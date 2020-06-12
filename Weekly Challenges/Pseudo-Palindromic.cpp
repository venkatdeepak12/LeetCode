/*

Given a binary tree where node values are digits from 1 to 9.
A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

Example 1:

Input: root = [2,3,1,3,1,null,1]
Output: 2 
Explanation: The figure above represents the given binary tree. 
There are three paths going from the root node to leaf nodes: the red path [2,3,3],
the green path [2,1,1], and the path [2,3,1]. 
Among these paths only red path and green path are pseudo-palindromic paths since the red path [2,3,3] 
can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).

*/

//Code:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count=0;
    bool checkpalindrome(int path[],int n)
    {
        map<int,int> mp;
        map<int, int>::iterator it; 
        int odd=0;
        for(int i=0;i<n;i++)
        {
            mp[path[i]]++;
        }
        for(it=mp.begin();it!=mp.end();it++)
        {
            if(it->second%2!=0)
            {
                odd++;
            }
        }
        if(odd<=1)
        {
            return true;
        }
        return false;
    }
    void paths(TreeNode* root,int path[],int n)
    {
        
        if(root==NULL)
        {
            return;
        }
        path[n]=root->val;
        n++;
        if(root->left==NULL and root->right==NULL)
        {
            if(checkpalindrome(path,n))
            {
                count++;   
            }
        }
        else
        {
            paths(root->left,path,n);
            paths(root->right,path,n); 
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int path[100];
        paths(root,path,0);
        return count;
    }
};

 
