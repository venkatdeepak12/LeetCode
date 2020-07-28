/*

In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 Example 1:

Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.


Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.


*/

//Code:

class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int i,j,k,c=0,m,n;
        bool changed=false;
        int no=2;
        n=grid.size();
        m=grid[0].size();
        while(true)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    if(grid[i][j]==no)
                    {
                        if(i+1<n)
                        {
                            if(grid[i+1][j]==1)
                            {
                                grid[i+1][j]=grid[i][j]+1;
                                changed=true;
                            }
                        }
                        if(i-1>=0)
                        {
                            if(grid[i-1][j]==1)
                            {
                                grid[i-1][j]=grid[i][j]+1;
                                changed=true;
                            }
                        }
                        if(j+1<m)
                        {
                            if(grid[i][j+1]==1)
                            {
                                grid[i][j+1]=grid[i][j]+1;
                                changed=true;
                            }
                        }
                        if(j-1>=0)
                        {
                            if(grid[i][j-1]==1)
                            {
                                grid[i][j-1]=grid[i][j]+1;
                                changed=true;
                            }
                        }
                    }
                    
                }
                
            }
            if(!changed)
            {
                break;
            }
            changed=false;
            no++;
           
            
        }
         for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    if(grid[i][j]==1) return -1;
                        
                }
            }
            
        return no-2;
    }
};
