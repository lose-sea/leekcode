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
        stack<char> st; 
        int len = s.size(); 
        for (int i = 0; i < len; i++) {
            if (s[i] != st.top()) {
                st.pop(); 
                st.push(s[i]); 
            } 
        }
    }
};
// @lc code=end

