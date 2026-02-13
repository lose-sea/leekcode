/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
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
//     int coinChange(vector<int>& coins, int amount) {
//         vector<uint64_t> dp(amount + 1, amount + 1);  
//         dp[0] = 0; 
//         for (int i = 0; i < coins.size(); i++) {
//             for (int j = 0; j <= amount; j++) {
//                 if (j >= coins[i]) {
//                     dp[j] = min(dp[j], dp[j - coins[i]] + 1); 
//                 }
//             }
//         } 
//         return dp[amount] > amount ? -1 : dp[amount]; 
//     }
// };





class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<uint64_t> dp(amount + 1, amount + 1); 
        dp[0] = 0; 
        for (int i = 0; i < coins.size(); i++) {
            for (int j = 0; j <= amount; j++) {
                if (j >= coins[i]) {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1); 
                }
            }
        } 
        return dp[amount] > amount ? -1 : dp[amount]; 
    }
};
// @lc code=end

