/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
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
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(5, 0));  
        dp[0][1] = -prices[0]; 
        for (int i = 1; i < prices.size(); i++) {
            dp[i][1] = max({dp[i - 1][1], dp[i - 1][2] - prices[i], dp[i - 1][4] - prices[i]}); 
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][4]); 
            dp[i][3] = dp[i - 1][1] + prices[i]; 
            dp[i][4] = dp[i - 1][3]; 
        } 
        return max({dp[prices.size() - 1][2], dp[prices.size() - 1][3], dp[prices.size() - 1][4]}); 
    }
};
// @lc code=end

