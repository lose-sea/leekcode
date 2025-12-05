/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
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
    string reverseStr(string s, int k) {
        int len = s.length(); 
        for (int i = 0; i < len; i += 2 * k) { 
            auto end = min(i + k, len); 
            reverse(s.begin() + i, s.begin() + end); 
        } 
        return s; 
    } 
};
// @lc code=end

