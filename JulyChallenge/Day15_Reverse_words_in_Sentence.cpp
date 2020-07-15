/*

Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"

Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.


Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

*/

//Code:

class Solution {
public:
    string reverseWords(string s) {
        string ans[1000],word="";
        int k=0;
        int space[1000],sp=0;
        int f=0;
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]==' ')
            {
                if(word!="")
                {
                     ans[k]=word;
                     word="";
                     k++;
                }
            }
            else
            {
                word+=s[i];
            }
        }
        if(word!="")
        {
            ans[k]=word;
            k++;
        }
        word="";
        f=0;
        cout<<"k= "<<k<<endl;
        for(int i=k-1;i>=0;i--)
        {
            if(i!=0)
            {
                word+=ans[i];
                word+=" ";
            }
            else
            {
                word+=ans[i];
            }
        }
        
   
        return word;
    }
};
