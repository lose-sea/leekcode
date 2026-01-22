/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
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
#include<numeric>
using namespace std;
// @lc code=start
// class Solution {
// public:
//     int fib(int n) {
//         vector<int> dp(2, 1); 
//         int sum = 0; 
//         if (n == 0) {
//             return 0; 
//         }
//         if (n <= 2) {
//             return 1; 
//         } 
//         for (int i = 3; i <= n; i++) { 
//             sum = dp[0] + dp[1]; 
//             dp[0] = dp[1]; 
//             dp[1] = sum; 
//         } 
//         return sum; 
//     }
// }; 

// class Solution {
// public:
//     int fib(int n) {
//         vector<int> dp; 
//         dp.push_back(0); 
//         dp.push_back(1); 
//         for (int i = 2; i <= n; i++) {
//             dp.push_back(dp[i - 1] + dp[i - 2]); 
//         } 
//         return dp[n]; 
//     }
// }; 

class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n; 
        } 
        return fib(n - 1) + fib(n - 2); 
    }
}; 
// @lc code=end

