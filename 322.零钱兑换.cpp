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
        vector<vector<uint64_t>> dp(coins.size(), vector<uint64_t>(amount + 1, amount + 1));  
        for (int i = 0; i < coins.size(); i++) {
            dp[i][0] = 0; 
        } 
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0 && coins[0] != 0) {
                dp[0][i] = i / coins[0]; 
            } 
        }
        for (int i = 1; i < coins.size(); i++) {
            for (int j = 0; j <= amount; j++) { 
                if (j >= coins[i]) {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i]] + 1); 
                } else {
                    dp[i][j] = dp[i - 1][j]; 
                }
            }
        } 
        return dp[coins.size() - 1][amount] > amount ? -1 : dp[coins.size() - 1][amount]; 
    }
};
// @lc code=end

