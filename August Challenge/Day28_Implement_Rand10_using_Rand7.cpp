/*

Given a function rand7 which generates a uniform random integer in the range 1 to 7, write a function rand10 which generates a uniform random integer in the range 1 to 10.

Do NOT use system's Math.random().

 

Example 1:

Input: 1
Output: [7]
Example 2:

Input: 2
Output: [8,4]
Example 3:

Input: 3
Output: [8,1,10]

*/

//Code:

class Solution {
public:
    int rand10() {
       int i,j;
    while( (i = rand7()) > 6);  // P(i is even) = P(i is odd) = 0.5
    while( (j = rand7()) > 5);  // P(j==1) = P(j==2) = P(j==3) = P(j==4) = P(j==5) = 0.2
    return (i&1) ? j : j+5;
    }
};
