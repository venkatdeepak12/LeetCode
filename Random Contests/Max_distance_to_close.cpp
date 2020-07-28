/*

In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty. 

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to closest person.

Example 1:

Input: [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
Example 2:

Input: [1,0,0,0]
Output: 3
Explanation: 
If Alex sits in the last seat, the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.


*/

//Code:

class Solution {
public:
    int maxDistToClosest(vector<int>& s) {
        int n=s.size();
        int a[n],max=-1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==0 and f==1)
            {
                a[i]=a[i-1]+1;
            }
            else if(s[i]==0 and f==0)
            {
                f=1;
                a[i]=1;
            }
            else 
            {
                a[i]=-1;
                f=0;
            } 
        }      
       for(int i=0;i<n;i++)
        {
           if( a[i]!=-1)
            {
                if(i-a[i]+1==0)
                {
                    if(a[i]>max)
                    {
                        max=a[i];
                    }
                }
               else if(i==n-1)
               {
                   if(a[i]>max)
                    {
                        max=a[i];
                    }
               }
               else
               {
                int h=a[i];
                if(a[i]%2!=0)
                {
                    h++;
                }
                if(max<h/2)
                {
                    max=h/2;
                }
               }
            }   
        }
        return max;      
    }
};
