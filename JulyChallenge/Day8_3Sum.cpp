/*

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[ [-1, 0, 1], [-1, -1, 2] ]

*/

//Code:

//Two pointer method:

class Solution {
public:
   
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i,j,k=0,ans;
        vector<vector<int>> res;
        set<vector<int>> s;
        int n=nums.size();
        if(n<3)
        {
            return res;
        }

        sort(nums.begin(),nums.end());
        for(i=0;i<n-2;i++)
        {
           
            int l=i+1;
            int r=n-1;
            while(l<r)
            {
                k=nums[i]+nums[l]+nums[r];
                if(k==0)
                {
                    s.insert({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
                else if(k>0)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
                      
        }
        
        for (auto i: s)
        {
            res.push_back(i);
        }
       return res;
        
        
    }
};
