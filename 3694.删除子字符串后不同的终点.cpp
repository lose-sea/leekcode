/*
 * @lc app=leetcode.cn id=3694 lang=cpp
 *
 * [3694] 删除子字符串后不同的终点
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
#include<deque> 
using namespace std;
// @lc code=start
class Solution {
public: 
    int distinctPoints(string s, int k) { 
        int n = s.size(); 
        unordered_set<long long> st;  
        int x = 0; 
        int y = 0; 
        for (int i = 0; i < n; i++) {
            switch(s[i]) {
                case 'L': x--; break; 
                case 'R': x++; break; 
                case 'D': y--; break; 
                case 'U': y++; break;  
            }  
            
            int left = i + 1 - k; 
            if (left < 0) {
                continue; 
            } 
            st.insert(1LL * (x + n) << 32 | (y + n));  
            
            switch(s[left]) {
                case 'L': x++; break; 
                case 'R': x--; break; 
                case 'D': y++; break; 
                case 'U': y--; break;  
            }  
        } 
        return st.size(); 
    }
};
// @lc code=end

