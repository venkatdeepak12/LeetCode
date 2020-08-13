/*

Design an Iterator class, which has:

A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
A function next() that returns the next combination of length combinationLength in lexicographical order.
A function hasNext() that returns True if and only if there exists a next combination.
 

Example:

CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false


*/

//Code:

class CombinationIterator {
public:
    int c=0;
    vector<vector<char>> ans;
    void comb(vector<char> ch,int co,vector<char> t, int ind,int i)
    {
        if(ind==co)   // all subets of length co
        {
            ans.push_back(t);
            return;
        }
        if(i>=ch.size())
        {
            return;
        }
        t.push_back(ch[i]);
        comb(ch,co,t,ind+1,i+1);
        t.pop_back();
        comb(ch,co,t,ind,i+1);
    }
    void sets(vector<char> ch,int co)
    {
        vector<char> t;
        comb(ch,co,t,0,0);
    }
    CombinationIterator(string cha, int com) {
        sort(cha.begin(),cha.end());
        vector<char> v;
        for(int i=0;i<cha.length();i++)
        {
               v.push_back(cha[i]);
        } 
        sets(v,com);
    }
    
    string next() {
        string strn;
        for(int i=0;i<ans[c].size();i++)
        {
            strn+=ans[c][i];   
        }
        c++;
        return strn;
    }
    
    bool hasNext() {
        if(c==ans.size())
        {
            return false;
        }
        return true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
