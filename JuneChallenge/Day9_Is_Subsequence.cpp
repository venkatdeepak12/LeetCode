/*

Given a string s and a string t, check if s is subsequence of t.

A subsequence of a string is a new string which is formed from the original string by
deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters.
(ie, "ace" is a subsequence of "abcde" while "aec" is not).

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence.
In this scenario, how would you change your code?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true

*/

//Code:

class Solution {
public:
    bool isSubsequence(string s, string t) {
        long i,j,k;
        k=0;
        if(t.length()==0 and s.length()==0)
        {
            return true;
        }
        for(i=0;i<t.length();i++)
        {
            if(t[i]==s[k])
            {
                k++;
            }
            if(k==s.length())
            {
                return true;
            }
        }
        return false;
        
    }
};
