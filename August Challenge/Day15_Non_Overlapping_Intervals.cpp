/*

Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:

Input: [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:

Input: [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

*/

//Code:

class Solution {
public:
    static bool comp(const vector<int>& a,const vector<int>&b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        stack<pair<int,int>> s;
        int count=0;
        if(intervals.size()==0) return count;
        s.push({intervals[0][0],intervals[0][1]});
        for(int i=1;i<intervals.size();i++)
        {
            auto t=s.top();
            
            if(t.second<=intervals[i][0])
            {
                s.push({intervals[i][0],intervals[i][1]});
            }
            else
            {
                count++;
            }
        }
        return count;
    }
};
