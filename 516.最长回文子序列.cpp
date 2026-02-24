/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
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
    int longestPalindromeSubseq(string s) {
        if (s.size() <= 1) {
            return s.size(); 
        } 
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0)); 
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = 1; 
        } 
        for (int i = s.size() - 2; i >= 0; i--) {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2; 
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); 
                }
            }
        } 
        return dp[0][s.size() - 1]; 
    }
};
// @lc code=end

