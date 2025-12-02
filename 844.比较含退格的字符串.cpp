/*
 * @lc app=leetcode.cn id=844 lang=cpp  
 * 
 * [844] 比较含退格的字符串 
 */ 
#include<iostream> 
#include<climits> 
#include<vector> 
#include<algorithm>
using namespace std; 
// @lc code=start 
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1; 
        string t1; 
        for (int i = 0; i < s.size(); i++) { 
            if (s.at(i) != '#') {
                s1.push_back(s[i]); 
            } else {
                if (!s1.empty()) {
                    s1.pop_back(); 
                }
            }
        } 
        for (int i = 0; i < t.size(); i++) { 
            if (t.at(i) != '#') {
                t1.push_back(t[i]); 
            } else {
                if (!t1.empty()) {
                    t1.pop_back(); 
                }
            }
        } 
        return s1 == t1; 
    }
};
// @lc code=end

