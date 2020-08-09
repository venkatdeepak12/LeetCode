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
    int orangesRotting(vector<vector<int>>& a) {
        int no=2,i,j,m,n;
        n=a.size();
        m=a[0].size();
        bool check=true;
        while(1)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    if(a[i][j]==no)
                    {
                        if(i+1<n and a[i+1][j]==1)
                        {
                            check = false;
                            a[i+1][j]=a[i][j]+1;
                        }
                        if(i-1>=0 and a[i-1][j]==1)
                        {
                            check = false;
                            a[i-1][j]=a[i][j]+1;
                        }
                        if(j+1<m and a[i][j+1]==1)
                        {
                            check = false;
                            a[i][j+1]=a[i][j]+1;
                        }
                        if(j-1>=0 and a[i][j-1]==1)
                        {
                            check = false;
                            a[i][j-1]=a[i][j]+1;
                        }
                    }
                }
            }
            if(check==true)
            {
                break;
            }
            no++;
            check=true;
            
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(a[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return no-2;
    }
};
