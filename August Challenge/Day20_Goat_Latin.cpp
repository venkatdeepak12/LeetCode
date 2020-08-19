/*

A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
For example, the word 'apple' becomes 'applema'.
 
If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".
 
Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
Return the final sentence representing the conversion from S to Goat Latin. 

 

Example 1:

Input: "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
Example 2:

Input: "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"

*/

//Code:


class Solution {

public:
    bool vowel(char c)
    {
        if(c=='A'||c=='a'||c=='E'||c=='e'||c=='I'||c=='i'||c=='O'||c=='o'||c=='U'||c=='u')
        {
            return true;
        }
        return false;
    }
    string check(string s)
    {
        string ans;
        for(int i=0;s[i]!='\0';i++)
        {
            if(i!=0)
            {
                ans+=s[i];
            }
        }
        return ans+s[0];
    }
    string toGoatLatin(string s) {
        int i,j,count=1;
        string ans;
        vector<string> res;
        istringstream ss(s); 
        do {  
            string word; 
            ss >> word; 
            res.push_back(word);
          } while (ss); 
        string add="a";
        for(i=0;i<res.size()-1;i++)
        {
            string st=res[i];
            if(vowel(st[0]))
            {
                ans+=st+"ma"+add;
            }
            else
            {
                st=check(st);
                ans+=st+"ma"+add;
            }
            add+="a";
            if(i<res.size()-2)
            {
                ans+=" ";
            }
        }
        return ans;     
    }
};

 
