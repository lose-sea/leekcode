/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
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
    // 判断是否合法
    bool isValid(int row, int col, char val, vector<vector<char>>& board) { 
        // 判断同一行
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == val) {
                return false; 
            }
        } 
        // 判断同一列 
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == val) {
                return false; 
            }
        }  
        // 检查九宫格
        int startRow = (row / 3) * 3; 
        int startCol = (col / 3) * 3; 
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == val) {
                    return false; 
                }
            }
        } 
        return true; 
    }  

    bool backTracking(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {
                        if (isValid(i, j, k, board)) {
                            board[i][j] = k; 
                            if (backTracking(board)) {
                                return true; 
                            } 
                            board[i][j] = '.';   
                        }
                    } 
                    return false;  
                } 
            }
        } 
        return true; 
    }

    void solveSudoku(vector<vector<char>>& board) {
        backTracking(board); 
    }
}; 
// @lc code=end

