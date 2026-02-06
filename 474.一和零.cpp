/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
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
// class Solution {
// public:
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         int len = strs.size(); 
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); 
//         for (string str : strs) {
//             int oneNum = 0; 
//             int zeroNum = 0; 
//             for (char c : str) {
//                 if (c == '0') {
//                     zeroNum++; 
//                 } else {
//                     oneNum++; 
//                 }
//             } 
//             for (int i = m; i >= zeroNum; i--) {
//                 for (int j = n; j >= oneNum; j--) {
//                     dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum]  + 1); 
//                 }
//             }
//         } 
//         return dp[m][n]; 
//     }
// };

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
       int len = strs.size();  
       vector<vector<int>> dp(m + 1, vector<int>(n, 0));  
       dp[0][0] = 0; 
       for (string str : strs) { 
            int zeroNum = 0; 
            int oneNum = 0; 
            for (char ch : str) {
                if (ch == '0') {
                    zeroNum++; 
                } else {
                    oneNum++; 
                }
            } 
            for (int i = m; i >= zeroNum; i--) {
                for (int j = n; j >= oneNum; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1); 
                }
            }
       } 
       return dp[m][n]; 
    }
};
// @lc code=end

