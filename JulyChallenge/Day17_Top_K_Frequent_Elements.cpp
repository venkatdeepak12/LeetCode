/*

Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]

*/

//Code:

class Solution {
public:
    static bool cmp(pair<int,int> &a,pair<int,int> &b)
    {
        return a.second>b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        vector<int> ans;
        vector<pair<int,int> >s;
        if(nums.size()==0) return ans;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto i:mp)
        {
           s.push_back(i); 
        }
        sort(s.begin(),s.end(),cmp);
        int count=0;
        for(auto i:s)
        {
            if(count<k)
            {
                ans.push_back(i.first);
                count++;
            }
            else
            {
                break;
            }
           
        }
        
        return ans;
    }
};

//We can use priority queue also....... :)
