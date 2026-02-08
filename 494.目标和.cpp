/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
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
#include<map> 
#include<stack> 
#include<deque>  
#include<numeric> 
using namespace std; 
// @lc code=start 
// 二维dp数组
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int sum = accumulate(nums.begin(), nums.end(), 0); 
//         if (abs(target) > sum) {
//             return 0; 
//         } 
//         if ((target + sum) % 2 == 1) {
//             return 0; 
//         } 
//         int s = (target + sum) / 2;  
//         vector<vector<int>> dp(nums.size(), vector<int>(s + 1, 0)); 
//         dp[0][0] = 1;   
//         if (nums[0] <= s) {
//             dp[0][nums[0]] = 1;  
//         }
        

//         // 考虑物品数值为0的情况 
//         int numZero = 0;  
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] == 0) {
//                 numZero++; 
//             }
//             dp[i][0] = (int)pow(2, numZero); 
//         }  

//         for (int i = 1; i < nums.size(); i++) {
//             for (int j = 0; j <= s; j++) {
//                 if (j < nums[i]) {
//                     dp[i][j] = dp[i - 1][j]; 
//                 } else {   
//                     dp[i][j] = dp[i - 1][j] + dp[i -1][j - nums[i]]; 
//                 }  
//             }  
//         } 
//         return dp[nums.size() - 1][s]; 
//     }
// };  



// // 一维dp数组
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int sum = accumulate(nums.begin(), nums.end(), 0); 
//         if (abs(target) > sum) {
//             return 0; 
//         } 
//         if ((target + sum) % 2 == 1) {
//             return 0; 
//         } 
//         int s = (target + sum) / 2;  
//         vector<int> dp(s + 1, 0); 
//         dp[0] = 1; 
//         for (int i = 0; i < nums.size(); i++) { 
//             for (int j = s; j >= nums[i]; j--) { 
//                 dp[j] += dp[j - nums[i]]; 
//             }
//         }
//         return dp[s]; 
//     }
// };



// // 二维dp数组
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int sum = accumulate(nums.begin(), nums.end(), 0); 
//         if (abs(target) > sum) {
//             return 0; 
//         } 
//         if ((target + sum) % 2 == 1) {
//             return 0; 
//         } 
//         int s = (target + sum) / 2;  
//         vector<vector<int>> dp(nums.size(), vector<int>(s + 1, 0)); 
//         dp[0][0] = 1; 

//         if (nums[0] <= s) {
//             dp[0][nums[0]] = 1; 
//         }

//         int zero_num = 0; 
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] == 0) {
//                 zero_num++; 
//             } 
//             dp[i][0] = pow(2, zero_num); 
//         } 
//         for (int i = 1; i < nums.size(); i++) {
//             for (int j = 0; j <= s; j++) {
//                 if (j >= nums[i]) {
//                     dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]]; 
//                 } else {
//                     dp[i][j] = dp[i - 1][j]; 
//                 }
//             }
//         }
//         return dp[nums.size() - 1][s]; 
//     }
// };   



// 一维dp数组
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0); 
        if (abs(target) > sum) {
            return 0; 
        } 
        if ((target + sum) % 2 == 1) {
            return 0; 
        } 
        int s = (target + sum) / 2;  
        vector<int> dp(s + 1, 0); 
        dp[0] = 1; 
        for (int i = 0; i < nums.size(); i++) {
            for (int j = s; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]]; 
            }
        }
        return dp[s]; 
    }
};
// @lc code=end

