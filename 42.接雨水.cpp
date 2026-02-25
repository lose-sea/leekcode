/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
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

// //单调栈 
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         stack<int> sk;  
//         sk.push(0);  
//         int sum = 0; 
//         for (int i = 1; i < height.size(); i++) {
//             while (!sk.empty() && height[i] > height[sk.top()]) {
//                 int mid = sk.top(); 
//                 sk.pop(); 
//                 if (!sk.empty()) {
//                     int h = min(height[sk.top()], height[i]) - height[mid]; 
//                     int w = i - sk.top() - 1;  
//                     sum += h * w; 
//                 }
//             } 
//             sk.push(i); 
//         }  
//         return sum; 
//     }
// };



// @lc code=end

