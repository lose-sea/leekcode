/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */
#include<iostream> 
#include<set> 
#include<unordered_set> 
#include<unordered_map>
#include<vector> 
#include<algorithm>   
#include<queue>   
#include<cmath>
#include<string> 
#include<cstdint>
#include<map> 
#include<stack> 
#include<deque>  
#include<numeric> 
using namespace std; 
// @lc code=start 
// // 二维数组
// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         int len = coins.size(); 
//         vector<vector<uint64_t>> dp(coins.size(), vector<uint64_t>(amount + 1, 0));  
//         for (int i = 0; i <= amount; i++) {
//             if (i % coins[0] == 0) {
//                 dp[0][i] = 1; 
//             }
//         }  
//         for (int i = 1; i < len; i++) {
//             for (int j = 0; j <= amount; j++) { 
//                 if (coins[i] > j) {
//                     dp[i][j] = dp[i - 1][j]; 
//                 } else {
//                     dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]]; 
//                 }
//             }
//         }
//         return dp[coins.size() - 1][amount]; 
//     }
// }; 


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<uint64_t> dp(amount + 1, 0);  
        dp[0] = 1;  
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]]; 
            }
        } 
        return dp[amount]; 
    }
};
// @lc code=end

