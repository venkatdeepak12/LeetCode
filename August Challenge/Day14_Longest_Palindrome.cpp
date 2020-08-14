/*

Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.


*/

//Code:

class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;
        int i=0;
        while(i<s.length())
        {
            mp[s[i]]++;
            i++;
        }
        int flag=0,ans=0;
        for(auto j: mp)
        {
            if(j.second%2==0)
            {
                ans+=j.second;
            }
            else
            {
                if(flag==0)
                {
                    ans+=j.second;
                    flag=1;
                }
                else
                {
                    ans+=j.second-1;
                }       
            }
        }
        return ans;
    }
};
