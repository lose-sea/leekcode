/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
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
//     int climbStairs(int n) {
//         if (n <= 2) {
//             return  n; 
//         } 
//         vector<int> dp(n + 1); 
//         dp[1] = 1; 
//         dp[2] = 2; 
//         for (int i = 3; i <= n; i++) {
//             dp[i] = dp[i - 1] + dp[i - 2]; 
//         } 
//         return dp[n]; 

//     }
// };

class Solution {
public:
    int climbStairs(int n) {
        if  (n <= 2) {
            return n; 
        } 
        vector<int> dp(n + 1); 
        dp[1] = 1; 
        dp[2] = 2; 
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2]; 
        } 
        return dp[n]; 
    }
};
// @lc code=end

