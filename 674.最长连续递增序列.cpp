/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
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

// // 滑动窗口
// class Solution {
// public:
//     int findLengthOfLCIS(vector<int>& nums) {
//         if (nums.size() <= 1) {
//             return nums.size(); 
//         } 
//         int curr = 1;  
//         int result = 1;  
//         for (int i = 1; i < nums.size(); i++) {
//             if (nums[i] > nums[i -1]) {
//                 curr++; 
//             } else {
//                 result = max(curr, result); 
//                 curr = 1; 
//             }
//         } 
//         result = max(curr, result); 
//         return result; 
//     }
// };


// 动态规划
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size(); 
        } 
        vector<int> dp(nums.size(), 1);  
        int result = 1; 
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1; 
            } else {
                result = max(dp[i - 1], result); 
            }
        } 
        result = max(dp[nums.size() - 1], result);  
        return result; 
    }
};
// @lc code=end

