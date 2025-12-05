/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
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
    bool isValid(string s) {
        stack<char> st;  
        int len = s.size();  
        for (int i = 0; i < len; i++) {
            if (s[i]  == '(') {
                st.push(')'); 
            } else if (s[i] == '[') {
                st.push(']'); 
            } else if (s[i] == '{') {
                st.push('}'); 
            } else {
                if (st.empty() || s[i] != st.top()) {
                    return false; 
                } else {
                    st.pop(); 
                }
            }
        } 
        if (st.empty()) {
            return true; 
        }
        return false;  
    }
};
// @lc code=end

