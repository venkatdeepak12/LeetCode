/*

Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/

//Code:

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> g(n,vector<int>(n));
        int total=n*n,i,j,u,d,l,r,it=1;
        l=u=0;
        r=d=n-1;
        while(it<=total)
        {
            for(i=l;i<=r;i++)
            {
                g[u][i]=it;
                it++;
            }
            u++;
            for(i=u;i<=d;i++)
            {
                g[i][r]=it;
                it++;
            }
            r--;
            for(i=r;i>=l;i--)
            {
                g[d][i]=it;
                it++;
            }
            d--;
            for(i=d;i>=u;i--)
            {
                g[i][l]=it;
                it++;
            }
            l++;
        }
        return g;   
    }
};
