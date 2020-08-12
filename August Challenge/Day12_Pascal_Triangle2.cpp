/*

Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?


*/

//Code:

class Solution {
public:
    
    vector<int> getRow(int n) {
        vector<int> A(n+1, 0);
        A[0] = 1;
        for(int i=1; i<n+1; i++)
            for(int j=i; j>=1; j--)
                A[j] += A[j-1];
        return A;
    
    }
};
