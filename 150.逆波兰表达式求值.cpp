/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
#include<iostream> 
#include<set> 
#include<unordered_set> 
#include<vector> 
#include<algorithm>   
#include<queue>  
#include<string>
#include<stack>
using namespace std; 
// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) { 
        int len = tokens.size(); 
        stack<long long> st; 
        for (int i = 0; i < len; i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                long long nums1 = st.top(); 
                st.pop(); 
                long long nums2 = st.top(); 
                st.pop();  
                if (tokens[i] == "+") {
                    st.push(nums1 + nums2); 
                } else if (tokens[i] == "-") {
                    st.push(nums2 - nums1); 
                } else if (tokens[i] == "*") {
                    st.push(nums1 * nums2); 
                } else {
                    st.push(nums2 / nums1); 
                } 
            } else {
                st.push(stoll(tokens[i])); 
            }
        } 
        return st.top(); 
    }
};  
// @lc code=end

