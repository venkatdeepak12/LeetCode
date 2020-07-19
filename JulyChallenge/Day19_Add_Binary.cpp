/*

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

*/

//Code:

class Solution {
public:
    string addBinary(string num1, string num2) {
        long long m,n,i,carry=0;
        string ans="";
        n=num1.length()-1;
        m=num2.length()-1;
        int sum=0;
        while(n>=0 || m>=0)
        {
            sum=0;
            if(n>=0 and m>=0)
            {
                sum+=carry+(num1[n]-'0')+(num2[m]-'0');
                if(sum==3)
                {
                    sum=1;
                    carry=1;
                }
                else if(sum==2)
                {
                    sum=0;
                    carry=1;
                }
                
                else
                {
                    carry=0;
                }
                n--;
                m--;
                //cout<<"vfdsdf\n";
            }
            else if(n>=0)
            {
                sum+=carry+(num1[n]-'0');
                if(sum==3)
                {
                    sum=1;
                    carry=1;
                }
                else if(sum==2)
                {
                    sum=0;
                    carry=1;
                }
                else
                {
                    
                    carry=0;
                }
               
                n--;
                 //cout<<"fdsffsf\n";
            }
            else if(m>=0)
            {
                sum+=carry+(num2[m]-'0');
                if(sum==3)
                {
                    sum=1;
                    carry=1;
                }
                else if(sum==2)
                {
                    sum=0;
                    carry=1;
                }
                else
                {
                    carry=0;
                }
                m--;
            }
            ans+=(sum+'0');
        }
        if(carry)
        {
            ans+=(carry+'0');
        }
        i=0;
        n=ans.length()-1;
        while(i<n)
        {
            swap(ans[i],ans[n]);
            i++;
            n--;
        }
        return ans;
        
    }
};
