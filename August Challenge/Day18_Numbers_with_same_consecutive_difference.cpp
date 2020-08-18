/*

Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

You may return the answer in any order.

 

Example 1:

Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]


*/

//Code:

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        queue<string> q;
        vector<int> ans;
        for(int i=1;i<=9;i++)
        {
            q.push(to_string(i));
        }
        if(n==1)
        {
            ans.push_back(0);
        }
        while(!q.empty())
        {
            string s=q.front();
            q.pop();
            if(s.length()==n)
            {
                int fill=stoi(s);
                ans.push_back(fill);
            }
            char ch=s.back();
            int last=ch-'0';
            string st=s;
            if((last+k<10 and s.length()<n))
            {
                s+=to_string(last+k);
                q.push(s);
            }
            if(k!=0  and last-k>=0 and st.length()<n)
            {
                st+=to_string(last-k);
                q.push(st);
            }
        }
        return ans;
    }
};
