/*

You are given coins of different denominations and a total amount of money. 
Write a function to compute the number of combinations that make up that amount.
You may assume that you have infinite number of each kind of coin.

 

Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

*/

//Code:

class Solution {
public:
    int change(int n, vector<int>& coins) 
    {
        
        int m=coins.size();
        if(m==0 and n==0)
        {
            return 1;
        }
        if(m==0) return 0;
        int a[n+1][m],i,j,x,y;
        for(i=0;i<m;i++)
        {
            a[0][i]=1;
        }
        for(i=1;i<n+1;i++)
        {
            for(j=0;j<m;j++)
            {
                x=0;
                y=0;
                if(i-coins[j]>=0)
                {
                    x=a[i-coins[j]][j];
                }
                if(j>=1)
                {
                    y=a[i][j-1];
                }
                a[i][j]=x+y;
            }        
        }
        // for(i=0;i<n+1;i++)
        // {
        //     for(j=0;j<m;j++)
        //     {
        //         cout<<a[i][j]<<" ";
        //     }
        // cout<<endl;
        // }
        return a[n][m-1];
    }
};
