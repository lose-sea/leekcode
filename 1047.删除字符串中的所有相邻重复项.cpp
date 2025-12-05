/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */
#include<iostream> 
#include<set> 
#include<unordered_set> 
#include<vector> 
#include<algorithm>   
#include<queue>  
#include<stack> 
using namespace std; 
// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        string st; 
        int len = s.size();  
        for (int i = 0; i < len; i++) { 
            if (!st.empty() && s[i] == st.back()) {
                st.pop_back(); 
            } else {
                st.push_back(s[i]); 
            }
        } 
        return st; 
    }
};
// @lc code=end

