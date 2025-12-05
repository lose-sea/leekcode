/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */
#include<iostream> 
#include<set> 
#include<unordered_set> 
#include<vector> 
#include<string> 
#include<algorithm>  
using namespace std;
// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size(); 
        for (int i = 1; i * 2 <= n; i++) {
            if (n % i == 0) { 
                bool match = true; 
                for (int j = i; j < n; j++) {
                    if (s[j] != s[j - i]) {
                        match = false; 
                        break; 
                    }
                } 
                if (match) {
                    return true; 
                }
            }
        } 
        return false; 
    }
};
// @lc code=end

