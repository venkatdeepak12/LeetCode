/*

There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], 
and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.


Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.

*/

//Code:

class Solution {
public:
   pair<int,int> Min(vector<pair<int,int>> dp, int pos) {  //To find Minimum pair
        int sum = 100000, i;
        pair<int, int> p;
        for(i=0;i<pos;i++) {
            if(dp[i].first + dp[i].second != 0 and dp[i].first + dp[i].second < sum) {
                sum = dp[i].first + dp[i].second;
                p = dp[i];
            }
        }
        return p;
    }
    
    int find(vector<vector<int>> costs, int bCost) {
        vector<vector<pair<int,int>>> dp(costs.size()/2 + 1, vector<pair<int,int>> (costs.size()));
        int i, j;
        for(i=0;i<costs.size();i++) {     
            dp[1][i] = {costs[i][0], bCost - costs[i][1]};    //add the values of city A and substract values of city B
        }
        for(j=2;j<=costs.size()/2;j++) {
            dp[j][0] = {0, 0};                     // Initialze them to 0,0
        }
        for(i=2;i<=costs.size()/2;i++) {
            for(j=i-1;j<costs.size();j++) {
                pair<int,int> p = Min(dp[i-1], j);    // Find minimum Pair
                dp[i][j] = {costs[j][0] + p.first , abs(p.second - costs[j][1])}; 
            }
        }
        int minCost = 100000;
        for(i=0;i<costs.size();i++) {
            int sum = dp[costs.size()/2][i].first + dp[costs.size()/2][i].second;
            if(sum != 0)
            minCost = min(minCost, sum);  //minimum cost of all pairs
        }
        return minCost;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int totalBCost = 0, totalACost = 0;
        for(auto it : costs) {   
            totalBCost += it[1];   //Add costs of city B
        }
        return find(costs,totalBCost);
    }
};
