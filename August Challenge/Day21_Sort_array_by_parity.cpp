/*

Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.


*/

//Code:

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> even,odd;
        int k,i=0;
        for(i=0;i<A.size();i++)
        {
            int count=A[i]%2;
            if(count==0)
            {
                even.push_back(A[i]);
            }
            else
            {
                odd.push_back(A[i]);
            }
        }
        even.insert(even.end(),odd.begin(),odd.end());
        return even;
    }
};
