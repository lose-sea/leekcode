/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
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
#include<cmath> 
#include<deque>  
#include<numeric>
using namespace std; 
// @lc code=start 

// // 暴力(会超时)
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         int m = temperatures.size();   
//         vector<int> answer(m, 0);  
//         answer[m - 1] = 0;   

//         for (int i = 0; i < m - 1; i++) { 
//             int count = 0; 
//             for (int j = i; j < m; j++) {
//                 if (temperatures[j] > temperatures[i]) {
//                     answer[i] = count;  
//                     break; 
//                 } else if (j == m - 1) {
//                     answer[i] = 0;  
//                 } else {
//                     count++; 
//                 } 
//             } 
//         } 
//         return answer; 
//     }
// }; 



// 单调栈
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) { 
        int m = temperatures.size();  
        vector<int> result(m, 0); 
        stack<int> sk;  
        sk.push(0); 
        for (int i = 1; i < m; i++) {
            while (!sk.empty() && temperatures[i] > temperatures[sk.top()]) {
                result[sk.top()] = i - sk.top();  
                sk.pop();  
            }
            sk.push(i);
        } 
        return result; 
    }
};
// @lc code=end

