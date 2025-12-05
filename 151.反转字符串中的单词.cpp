/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
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

    string reverseWords(string s) {
        int len = s.size(); 
        reverse(s.begin(), s.end());  
        int idx = 0; 
        for (int start = 0; start < len; start++) {
            if (s[start] != ' ') {
                if (idx != 0) {
                    s[idx++] = ' '; 
                } 
                    int end = start; 
                    while (end < len && s[end] != ' ') {
                        s[idx++] = s[end++]; 
                    }  
                    // 反转整个单词
                    reverse(s.begin() + idx - (end - start), s.begin() + idx); 
                    start = end; 
                
            } 
        } 
        s.erase(s.begin() + idx, s.end()); 
        return s; 
    }
};
// @lc code=end

