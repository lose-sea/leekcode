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

// // 常规
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {  
//         int result = 0; 
//         bool have = false; 
//         for (int i = 0; i < prices.size() - 1; i++) {
//             if (!have) {
//                 if (prices[i + 1] < prices[i]) {
//                     continue; 
//                 }  else {
//                     result = result - prices[i]; 
//                     have = true; 
//                 }
//             } else {
//                 if (prices[i + 1] >= prices[i]) {
//                     continue;  
//                 } else {
//                     result += prices[i]; 
//                     have = false; 
//                 } 
//             } 
//         } 
//         if (have) {
//             result += prices.back(); 
//         }
//         return result; 
//     } 
// };  


// 贪心算法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0; 
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] - prices[i - 1] > 0) {
                result += prices[i] - prices[i - 1]; 
            }
        } 
        return result; 
    }
};

// @lc code=end

