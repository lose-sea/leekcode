/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 娑旀澘宕犻懖锛勩偍閻ㄥ嫭娓舵担铏閺堬拷1锟�7
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


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         if (prices.size() == 0) {
//             return 0; 
//         } 
//         int minprices = prices[0]; 
//         int result = 0; 
//         for (int i = 1; i < prices.size(); i++) {
//             minprices = min(prices[i], minprices);  
//             result = max(result, prices[i] - minprices); 
//         }
//         return result; 
//     }
// };  


// // 贪心算法
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int result = 0; 
//         int minprice = prices[0]; 
//         for (int i = 0; i < prices.size(); i++) {
//             minprice = min(prices[i], minprice); 
//             result = max(result, prices[i] - minprice); 
//         } 
//         return result; 
//     }
// };



// 动态规划
class Solution {
public:  
    int maxProfit(vector<int>& prices) {
        
    }
};


// @lc code=end

