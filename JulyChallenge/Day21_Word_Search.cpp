/*

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3

*/

//Code:

class Solution {
public:
    bool vis[201][201];
    int h=0;
    
    bool safe(int i,int j,vector<vector<char>>& a,int k,string word)
    {
        if(i<0 or j<0 or i>=a.size() or j>=a[0].size() or vis[i][j]==true) return false;
        if(a[i][j]==word[k]) return true;
        return false;
    }
    
    void dfs(vector<vector<char>>& a,int i,int j,int k,string word)
    {   
        if(k==word.size())
        {
            h=1;
            return;  
        }
        vis[i][j]=true;
        char ch;
        if(safe(i+1,j,a,k,word))
        {
            dfs(a,i+1,j,k+1,word);
             if(h==1)
            {
                vis[i][j]=0;
                return ;
            }  
        }
         if(safe(i-1,j,a,k,word))
        {  
            dfs(a,i-1,j,k+1,word);
           
             if(h==1)
            {
                 vis[i][j]=0;
                return ;
            }    
        } 
        if(safe(i,j-1,a,k,word))
        {
            dfs(a,i,j-1,k+1,word);
           
             if(h==1)
            {
                 vis[i][j]=0;
                 return ;
            }     
        }
        if(safe(i,j+1,a,k,word))
        {
            dfs(a,i,j+1,k+1,word);
           
             if(h==1)
            {
                 vis[i][j]=0;
                 return ;
            }
        } 
        vis[i][j]=0;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int i,j,k;
        for(i=0;i<board.size();i++)
        {
            for(j=0;j<board[i].size();j++)
            {
                if(word[0]==board[i][j])
                { 
                    dfs(board,i,j,1,word);
                    if(h==1)
                    {
                        return true;
                    }
                }
            }
        }
       return false;
    }
};
