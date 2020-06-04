/*

Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.


Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

*/

//Code:

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i,len=s.size();
        for(i=0;i<len/2;i++)
        {
            swap(s[i],s[len-i-1]);
        }
            
    }
};

