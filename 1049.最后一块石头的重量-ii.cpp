/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
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
#include<numeric> 
using namespace std; 
// @lc code=start
// class Solution {
// public:
//     int lastStoneWeightII(vector<int>& stones) {
//         int sum = accumulate(stones.begin(), stones.end(), 0); 
//         int target = sum / 2;  
//         vector<int> dp(target + 1, 0); 
//         for (int i = 0; i < stones.size(); i++) {
//             for (int j = target; j >= stones[i]; j--) {
//                 dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]); 
//             }
//         } 
//         return sum - dp[target] - dp[target]; 
//     }
// };


// // 二维数组
// class Solution {
// public:
//     int lastStoneWeightII(vector<int>& stones) {
//         int sum = accumulate(stones.begin(), stones.end(), 0); 
//         int target = sum / 2; 
//         vector<vector<int>> dp(stones.size(), vector<int>(target + 1, 0)); 
//         for (int i = stones[0]; i <= target; i++) {
//             dp[0][i] = stones[0]; 
//         } 
//         for (int i = 1; i < stones.size(); i++) {
//             for (int j = 0; j <= target; j++) {
//                 if (j >= stones[i]) {
//                     dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]); 
//                 } else {
//                     dp[i][j] = dp[i - 1][j]; 
//                 }
//             }
//         }
//         return sum - dp[stones.size() - 1][target] * 2; 
//     }
// };  

// 一维数组
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0); 
        int target = sum / 2; 
        vector<int> dp(target + 1, 0); 
        for (int i = 0; i < stones.size(); i++) {
            for (int j = target; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]); 
            }
        }  
        return sum - dp[target] * 2; 
    }
};
// @lc code=end

