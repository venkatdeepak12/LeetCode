/*

Given a set of distinct positive integers, 
find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)


Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]

*/

//Code:

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        if(n==0)
        {
            return ans;
        }
        vector<int> divcount(n,1);
        vector<int> prev(n,-1);
        
        sort(nums.begin(),nums.end());
        int i,j,max=0;
        for(i=1;i<nums.size();i++)
        {
            for(j=0;j<i;j++)
            {
                
                if(nums[i]%nums[j]==0)
                {
                    if(divcount[i]<divcount[j]+1)
                    {
                        divcount[i]=divcount[j]+1;
                        prev[i]=j;
                    }
                        
                }
            }
            if(divcount[max]<divcount[i])
            {
                max=i;
            }
          
        }
        i=max;
        while(i>=0)
        {
            ans.push_back(nums[i]);
            i=prev[i];
        }
        return ans;
    }
};
