/*

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)


Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]

*/

//Code:

class Solution {
public:
    int maxProfit(vector<int>& prices){
     int n = prices.size();
		if( n<= 1) return 0;
		vector<int> buy(n, 0),cd(n, 0),sell(n, 0);
		cd[0] = -prices[0],buy[0] = 0,sell[0] = INT_MIN;
        
		for (int i = 1; i < n; i++) {
			buy[i]  = max(buy[i - 1], sell[i - 1]);
			cd[i]   = max(cd[i - 1], buy[i - 1] - prices[i]);
			sell[i] = cd[i - 1] + prices[i];
		}
		return max(buy[n-1], sell[n-1]);
	}
};
