/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
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
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset(wordDict.begin(), wordDict.end()); 
        vector<bool> dp(s.size() + 1, false); 
        dp[0] = true; 
        for (int i = 1; i <= s.size(); i++) {
            for (int j = i; j >= 0; j--) {
                string word = s.substr(j, i - j); 
                if (wordset.find(word) != wordset.end() && dp[j]) {
                    dp[i] = true; 
                }
            }
        }    
        return dp[s.size()]; 
    }
};
// @lc code=end

