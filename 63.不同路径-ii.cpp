/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) { 

        int m = obstacleGrid.size() - 1; 
        int n = obstacleGrid[0].size() - 1; 
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0)); 
        for (int i = 0; i < obstacleGrid[0].size(); i++) {
            if (obstacleGrid[0][i] != 1) {
                dp[0][i] = 1; 
            } else {
                break; 
            }
        } 
        for (int i = 0; i < obstacleGrid.size(); i++) {
            if (obstacleGrid[i][0] != 1) {
                dp[i][0] = 1; 
            } else {
                break; 
            }
        } 
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (obstacleGrid[i][j] != 1) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; 
                } else {
                    dp[i][j] = 0; 
                } 
            }
        } 
        return dp[m][n]; 
    }
};
// @lc code=end

