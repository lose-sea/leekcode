/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
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
using namespace std;
// @lc code=start
// class Solution {
// public:
//     int numSquares(int n) {
//         vector<int> dp(n + 1, 0); 
//         dp[0] = 0;  
//         for (int i = 0; i <= n; i++) {
//             dp[i] = i; 
//         }
//         for (int i = 2; i <= n; i++) {
//             for (int j = 0; j <= n; j++) { 
//                 if (j >= i * i) {
//                     dp[j] = min(dp[j], dp[j - i * i] + 1); 
//                 }
//             }
//         } 
//         return dp[n]; 
//     }
// };



class Solution {
public:
    int numSquares(int n) {
        vector<vector<int>> dp((int)(sqrt(n)) + 1, vector<int>(n + 1, 0));  
        
        for (int i = 0; i <= n; i++) {
            dp[1][i] = i; 
        } 
        for (int i = 2; i * i <= n; i++) {
            for (int j = 0; j <= n; j++) { 
                if (j >= i * i) {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - i * i] + 1); 
                } else {
                    dp[i][j] = dp[i - 1][j]; 
                }
            }
        } 
        return dp[(double)sqrt(n)][n]; 
    }
};
// @lc code=end

