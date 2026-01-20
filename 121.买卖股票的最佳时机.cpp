/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 涔板崠鑲＄エ鐨勬渶浣虫椂鏈�
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
        if (prices.size() == 0) {
            return 0; 
        } 
        int minprices = prices[0]; 
        int result = 0; 
        for (int i = 1; i < prices.size(); i++) {
            minprices = min(prices[i], minprices);  
            result = max(result, prices[i] - minprices); 
        }
        return result; 
    }
};
// @lc code=end

