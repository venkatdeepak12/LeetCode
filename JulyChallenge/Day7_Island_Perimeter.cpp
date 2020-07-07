/*

You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island 
(i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. 
The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example:

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16

*/

//Code:

class Solution {
public:
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int c=0,i,j;
        for(i=0;i<grid.size();i++)
        {
            for(j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    c++;
                }
            }
        }
        int ans=c*4;
        for(i=0;i<grid.size();i++)
        {
            for(j=0;j<grid[i].size();j++)
            {
                if(j-1>=0 and grid[i][j-1]==1 and grid[i][j]==1)
                {
                    ans-=2;
                }
                if(i-1>=0 and grid[i-1][j]==1 and grid[i][j]==1)
                {
                    ans-=2;
                }
            }
        }
        return ans;
    }
    
};
