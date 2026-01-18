/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
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
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) {
            return 0;
        } 
        size_t len = prices.size();  
        int result = 0; 
        for (size_t i = 0; i < len - 1; i++) { 
            if (prices[i + 1] - prices[i] > 0) {
                result += prices[i + 1] - prices[i]; 
            }
        } 
        return result; 
    }
};
// @lc code=end

