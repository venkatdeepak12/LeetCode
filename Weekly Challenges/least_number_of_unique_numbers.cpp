/*

Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

 

Example 1:

Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.


Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.

*/

//Code:

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp;
        
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        vector<vector<int>> v(mp.size(),vector<int>(2,0));
        int j=0;
        for(auto i:mp)
        {
            v[j][0]=(i.first);
            v[j][1]=(i.second);
            j++;
        }
      
        sort(v.begin(),v.end(),[](const vector<int>&a ,const vector<int>&b)
             {
                return a[1]<b[1]; 
             });
        
        int ans=mp.size();
        for(int i=0;i<v.size();i++)
        {
            if(k>0)
            {
                if(v[i][1]>k)
                {
                    v[i][1]-=k;
                    k=0;
                }
                else
                {
                    k-=v[i][1];
                    v[i][1]=0;
                    ans--;
                }
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};
