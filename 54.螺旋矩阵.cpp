/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include<iostream> 
#include<climits> 
#include<vector> 
#include<algorithm>
using namespace std; 
// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return {}; 
        }
        // 行数
        int m = matrix.size();  
        // 列数
        int n = matrix[0].size(); 
        // 元素总数
        int size = m * n; 
        vector<int> result; 
        result.resize(size); 
        int num = 0;  
        int top = 0; 
        int bottom = m - 1; 
        int left = 0; 
        int right = n - 1; 
        while (num < size) { 

            for (int i = left; i <= right && top <= bottom; i++) {
                result[num++] = matrix[top][i]; 
            } 
            top++; 
            for (int i = top; i <= bottom && left <= right; i++) {
                result[num++] = matrix[i][right];  
            } 
            right--; 
            for (int i = right; i >= left && top <= bottom; i--) {
                result[num++] = matrix[bottom][i]; 
            } 
            bottom--; 
            for (int i = bottom; i >= top && left <= right; i--) {
                result[num++] = matrix[i][left]; 
            } 
            left++; 
        } 
        return result;        
    }
}; 
// @lc code=end

