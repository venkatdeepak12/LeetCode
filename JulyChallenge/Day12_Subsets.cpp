/*

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

//Code:

class Solution {
public:
    vector<int>FindSubSet(int no,vector<int>&nums){
        vector<int>re;
        int i = 0;
        while(no){
            if(no&1){
                re.push_back(nums[i]);
            }
            i++;
            no>>=1;
        }
        return re;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        cout<<"n= "<<n<<endl;
        int total = 1<<n;            // shifting '1' n times...  towards left...gives 2 power n value....
        cout<<"total "<<total<<endl;
        for(int i=0;i<total;i++){
            vector<int>temp = FindSubSet(i,nums);
            ans.push_back(temp);
        }
        return ans;
    }
};
