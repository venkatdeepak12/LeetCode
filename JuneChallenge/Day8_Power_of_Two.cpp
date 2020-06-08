/*

Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true 
Explanation: 2 power 0 = 1

*/

//Code:

class Solution {
public:
    
    bool isPowerOfTwo(int n) {
        //cout<<n<<endl;
        if(n==0) return false;
        while(n%2==0)
        {
            n=n/2;
        }
        if(n==1) return true;
        return false;
        
    }
};
