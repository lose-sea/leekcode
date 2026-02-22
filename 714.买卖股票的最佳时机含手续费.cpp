/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */
#include<iostream> 
#include<set> 
#include<unordered_set> 
#include<unordered_map>
#include<vector> 
#include<algorithm>   
#include<queue>  
#include<string> 
#include<map> 
#include<stack> 
#include<cmath> 
#include<deque>  
#include<numeric>
using namespace std; 
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(3, 0)); 
        dp[0][1] = -prices[0];  
        for (int i = 1; i < prices.size(); i++) {
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] - prices[i]); 
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i] - fee); 
        } 
        return dp.back().back(); 
    }
};
// @lc code=end

