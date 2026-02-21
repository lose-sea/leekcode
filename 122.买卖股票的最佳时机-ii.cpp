/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
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
#include<deque> 
using namespace std; 
// @lc code=start
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         if (prices.size() == 1) {
//             return 0;
//         } 
//         size_t len = prices.size();  
//         int result = 0; 
//         for (size_t i = 0; i < len - 1; i++) { 
//             if (prices[i + 1] - prices[i] > 0) {
//                 result += prices[i + 1] - prices[i]; 
//             }
//         } 
//         return result; 
//     }
// };


// class Solution {
// public:;
//     int maxProfit(vector<int>& prices) {
//        if (prices.size() == 1) {
//             return 0; 
//        }  
//        int result = 0; 
//        for (int i = 1; i < prices.size(); i++) {
//             int currdiff = prices[i] - prices[i - 1]; 
//             if (currdiff > 0) {
//                 result += currdiff; 
//             }
//        } 
//        return result; 
//     }
// };



// 动态规划
class Solution {
public:  
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));  
        dp[0][1] = -prices[0]; 
        dp[0][0] = 0; 
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][1] + prices[i], dp[i - 1][0]); 
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]); 
        } 
        return dp[prices.size() - 1][0]; 
    }
};
// @lc code=end

