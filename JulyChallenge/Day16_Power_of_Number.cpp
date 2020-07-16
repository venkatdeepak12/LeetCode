/*

Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000

Example 2:

Input: 2.10000, 3
Output: 9.26100

Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2^-2 = 1/22 = 1/4 = 0.2500

*/

//Code:

class Solution {
public:
    double myPow(double x, long long n) {
        double res=1;
       if(n>0)
       {
        while(n)
        {
            if(n&1)
            {
                res=res*x;
            }
            x=x*x;
            n>>=1;
        }
       }
        else
        {
            n=n*-1;
            while(n)
            {
                if(n&1)
                {
                    res=res*(1/x);
                }
                x=(x*x);
                n>>=1;
            }
        }
        return res;
    }
};
