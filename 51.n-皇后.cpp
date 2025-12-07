/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
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

    vector<vector<string>> result;  

    void backTracking(int n, int row, vector<string>& chessboard) {
        if (row == n) {
            result.push_back(chessboard); 
        } 
        for (int col = 0; col < n; col++) {
            if (isValid(row, col, chessboard, n)) {
                chessboard[row][col] = 'Q'; 
                backTracking(n, row + 1, chessboard); 
                chessboard[row][col] = '.'; // 撤销皇后
            }
        }
    } 

    bool isValid(int row, int col, vector<string>& chessboard, int n) { 
        // 检查列 
        for (int i = 0; i < row; i++) {  
            if (chessboard[i][col] == 'Q') { 
                return false;  
            } 
        } 
        // 向左上方向检查
        for (int i  = row - 1, j = col - 1; j >= 0 && i >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') {
                return false; 
            }
        } 
        // 向右上方向检查
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false; 
            } 
        } 
        return true;  
    } 
 

    vector<vector<string>> solveNQueens(int n) { 
        vector<string> chessboard(n, string(n, '.'));  
        backTracking(n, 0, chessboard); 
        return result;  
    }
};
// @lc code=end

