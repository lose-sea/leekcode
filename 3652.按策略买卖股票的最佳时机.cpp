/*
 * @lc app=leetcode.cn id=3652 lang=cpp
 *
 * [3652] 按策略买卖股票的最佳时机
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

// 前缀和
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) { 
        long long curr = 0; 
        int len = prices.size(); 
        vector<long long> sum(1, 0); 
        vector<long long> seilsum(1,0); 
        for (int i = 0; i < len; i++) {
            seilsum.emplace_back(prices.at(i) + seilsum[i]); 
            sum.emplace_back(strategy.at(i) * prices.at(i) + sum[i]); 
        } 
        long long result = sum[len]; 
        for (int i = k; i <= len; i++) {
            curr = sum[i - k] + sum[len] - sum[i] + seilsum[i] - seilsum[i - k / 2];    
            result = max(result, curr); 
        } 
        return result; 
    }
};
// @lc code=end

