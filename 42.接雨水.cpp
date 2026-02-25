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



// // 暴力(超时)
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int sum = 0; 
//         for (int i = 1; i < height.size() - 1; i++) {
//             int rheight = height[i]; 
//             int lheight = height[i]; 
//             for (int r = i + 1; r < height.size(); r++) {
//                 if (height[r] > rheight) {
//                     rheight = height[r]; 
//                 } 
//             } 
//             for (int l = i - 1; l >= 0; l--) {
//                 if (height[l] > lheight) {
//                     lheight = height[l]; 
//                 }
//             } 
//             int h = min(lheight, rheight) - height[i]; 
//             if (h > 0) {
//                 sum += h; 
//             }
//         }  
//         return sum; 
//     }
// };



// 双指针优化
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) {
            return 0; 
        } 
        vector<int> maxleft(height.size(), 0); 
        vector<int> maxright(height.size(), 0); 
        
        maxleft[0] = height[0]; 
        for (int i = 1; i < height.size(); i++) {
            maxleft[i] = max(height[i], maxleft[i - 1]); 
        } 
        maxright[height.size() - 1] = height[height.size() - 1]; 
        for (int i = height.size() - 2; i >= 0; i--) {
            maxright[i] = max(height[i], maxright[i + 1]); 
        } 

        int sum = 0; 
        for (int i = 1; i < height.size() - 1; i++) {
            int count = min(maxleft[i], maxright[i]) - height[i]; 
            if (count > 0) {
                sum += count; 
            }
        } 
        return sum; 


    }
};

// @lc code=end

