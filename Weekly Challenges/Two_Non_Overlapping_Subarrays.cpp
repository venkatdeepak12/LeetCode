/*

Given an array of integers arr and an integer target.



You have to find two non-overlapping sub-arrays of arr each with sum equal target. 
There can be multiple answers so you have to find an answer where the sum of the lengths of the two sub-arrays is minimum.

Return the minimum sum of the lengths of the two required sub-arrays, or return -1 if you cannot find such two sub-arrays.

Example 1:

Input: arr = [3,2,2,4,3], target = 3
Output: 2
Explanation: Only two sub-arrays have sum = 3 ([3] and [3]). The sum of their lengths is 2.

Example 2:

Input: arr = [7,3,4,7], target = 7
Output: 2
Explanation: Although we have three non-overlapping sub-arrays of sum = 7 ([7], [3,4] and [7]), 
but we will choose the first and third sub-arrays as the sum of their lengths is 2.

*/

//Code:
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int i,j,count=0,n,k,index;
        n=arr.size();
        vector<int> cumsum;
        vector<int> len;
        for(i=0;i<n;i++)
        {
            if(i==0)
            {
                cumsum.push_back(arr[i]);
            }
            else
            {
                k=arr[i]+cumsum[i-1];
                cumsum.push_back(k);
            }
           // cout<<cumsum[i]<<"  ";
        }
        int last=0;
        index=-1;
        for(i=0;i<n;i++)
        {
            if(i==0)
            {
                if(cumsum[i]==target)
                {
                    len.push_back(1);
                    //cout<<" i=0\n";
                   // cout<<index<<"  ";
                    index=i;
                    last=0;
                }
            }
            else
            {
                
                if(cumsum[i]==target)
                {
                    len.push_back(i+1);
                    //cout<<" target= \n";
                   // cout<<index<<"  ";
                    index=i;
                    last=0;
                }
                else
                {
                    k=target;
                    for(j=i-1;j>=last;j--)
                    {
                        if(cumsum[i]-cumsum[j]>k)
                        {
                            break;
                        }
                        if(cumsum[i]-cumsum[j]==k)
                        {
                            if(index!=-1 and i-(i-j)<index and len.back()>=i-j)
                            {
                               // cout<<" ffd\n";
                                
                                    len.pop_back();
                                    len.push_back(i-j);
                                  
                            }
                            else
                            {
                                len.push_back(i-j); 
                            }
                             index=i;
                           // cout<<index<<"  ";
                             last=j;
                            
                            break;
                        }  
                    }
                }
            }
        }
        // for(i=0;i<len.size();i++)
        // {
        //     cout<<len[i]<<"  ";
        // }
        if(len.size()<=1)
        {
            return -1;
        }
        sort(len.begin(),len.end());
        return len[0]+len[1];
    }
    
    //[26,5,16,1,2,2,25,20,1,5,1,9,32,4,2,2,3,34,6,8,1,1,2,45,2,2,1,1,1,50,1,1,32,6,7,6,1,37]
//52
};
