/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
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

// 单调栈
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) { 
        int result = 0; 
        stack<int> sk;  
        heights.insert(heights.begin(), 0); 
        heights.push_back(0); 
        sk.push(0); 
        for (int i = 1; i < heights.size(); i++) { 
            while(heights[i] < heights[sk.top()]) {
                int mid = sk.top();  
                sk.pop(); 
                int w = i - sk.top() - 1; 
                int h = heights[mid]; 
                result = max(result, w * h); 
            }
            sk.push(i); 
        }  
        return result; 
    }
};
// @lc code=end

