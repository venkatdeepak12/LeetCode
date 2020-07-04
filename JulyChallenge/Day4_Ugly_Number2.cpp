/*

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

*/

//Code:

class Solution {
public:
    
    int min(int a,int b,int c)
    {
        vector<int> k;
        k.push_back(a);
        k.push_back(b);
        k.push_back(c);
        sort(k.begin(),k.end());
        return k[0];   
    }
    
    int nthUglyNumber(int n) 
    {
        int k;
        int o=0,t=0,f=0;
        vector<int> a;
        a.push_back(1);  
        
        while(a.size()<n)
        {
            
            k=min(a[o]*2,a[t]*3,a[f]*5);
            a.push_back(k);
            if(k==a[o]*2)
            {
                o++; 
            }
             if(k==a[t]*3) 
            {
                t++;
            }
             if(k==a[f]*5)
            {
                f++;
            }
           
        }
        return a[n-1];
    }
};
