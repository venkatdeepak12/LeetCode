/*

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right


Example 2:

Input: m = 7, n = 3
Output: 28

*/

//Code:

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector< vector<int>> a(m,vector<int>(n,0));
        a[0][0]=1;
        int i,j;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i-1>=0 and j-1>=0)
                {
                    a[i][j]=a[i][j-1]+a[i-1][j];
                }
                else if(i-1>=0)
                {
                    a[i][j]=a[i-1][j];
                }
                else if(j-1>=0)
                {
                    a[i][j]=a[i][j-1];
                }
            }
        }
        return a[m-1][n-1];
    }
};
