/*

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true
Example 2:

Input: 5
Output: false

*/

//CodE:
class Solution {
public:
    bool isPowerOfFour(int num) {
        
        while(num)
        {
            if(num==1) return true;
            if(num%4==0)
            {
                num/=4;
            }
            else
            {
                return false;
            }
            
        }
        return false;
    }
};

