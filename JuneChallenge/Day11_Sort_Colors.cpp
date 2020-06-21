/*
Question:
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent,
with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

*/

//Code:

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i,zero=0,one=0,two=0;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                zero++;
            }
            else if(nums[i]==1)
            {
                
                one++;
            }
            else if(nums[i]==2)
            {
                two++;
            }
        }
        two+=one+zero;
        one+=zero;
        for(i=0;i<nums.size();i++)
        {
            if(i<zero)
            {
                nums[i]=0;
            }
            if(i<one && i>=zero)
            {
                nums[i]=1;
            }
            if(i<two && i>=one)
            {
                nums[i]=2;
            }
        }
    }
};
