/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
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
// class Solution {
// public: 

//     int findContentChildren(vector<int>& g, vector<int>& s) {
//         sort(g.begin(), g.end()); 
//         sort(s.begin(), s.end()); 
//         int index = s.size() - 1; 
//         int result = 0; 
//         for (int i = g.size() - 1; i >= 0; i--) {
//             if (index >= 0 && s[index] >= g[i]) {
//                 result++;  
//                 index--; 
//             }
//         } 
//         return result; 
//     }
// };


class Solution {
public: 
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (g.empty() || s.empty()) {
            return 0; 
        } 
        sort(s.begin(), s.end()); 
        sort(g.begin(), g.end()); 
        int result = 0; 
        int index = s.size() - 1; 
        for (int i = g.size() - 1; i >= 0; i--) {
            if (index >= 0 && s[index] >= g[i]) {
                result++; 
                index--; 
            }
        } 
        return result; 
    }
};
// @lc code=end

