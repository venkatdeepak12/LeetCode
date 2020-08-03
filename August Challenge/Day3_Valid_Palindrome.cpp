/*

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false

*/

//Code:

class Solution {
public:
    bool isPalindrome(string s) {
        string st,rev;
        int i,j,n;
        i=0;
        n=s.length();
        if(n==0) return true;
        while(s[i]!='\0')
        {
            if(isalnum(s[i]))
            {
                if(isalpha(s[i]))
                {
                    st+=(tolower(s[i]));
                }
                else
                {
                    st+=s[i];
                }
            }
            i++;
        }
        rev=st;
        i=0;
        n=st.length()-1;
        //cout<<st;
        while(i<n)
        {
            if(st[i]!=rev[n])
            {
                return false;
            }
            i++;
            n--;
        }
        return true;
    }
};
