/*

Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 
 */
 
 //Code:
 
 class Solution {
public:
    int a[10000]={0};
    int numTrees(int n)
    {
        int i,j;
        if(n==0)
        {
            return 0;
        }
        a[0]=1;
        a[1]=1;
        a[2]=2;
        if(n<=2)
        {
            return a[n];
        }
        for(i=3;i<=n;i++)
        {
            int sum=0;
            for(j=1;j<=i;j++)
            {
                sum+=(a[i-j]*a[j-1]);
            }
            a[i]=sum;
        }
        return a[n];
    }
};
