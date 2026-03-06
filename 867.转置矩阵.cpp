/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
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
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(); 
        int n = matrix[0].size(); 
        vector<vector<int>> result(n, vector<int>(m, 0)); 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[j][i] = matrix[i][j]; 
            }
        } 
        return result; 
    }
};
// @lc code=end

