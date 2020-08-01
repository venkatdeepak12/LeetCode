/*

Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
 

Example 1:

Input: "USA"
Output: True
 

Example 2:

Input: "FlaG"
Output: False


*/

//Code:

class Solution {
public:
    bool detectCapitalUse(string w) {
        int i=0,j,f=0;
        while(w[i]!='\0')
        {
            if(isupper(w[0]))
            {
                if(i!=0)
               {
                if(isupper(w[i]) and (f==0 or f==1))
                {
                    f=1;
                }
                else if(islower(w[i]) and (f==0 or f==2))
                {
                    f=2;
                }
                else
                {
                    return false;
                }
            
               }
            }
            else
            {
                if(islower(w[i]) and (f==0 or f==2))
                {
                    f=2;
                }
                else
                {
                    return false;
                }
            }
            
            i++;
        }
        return true;
    }
};
