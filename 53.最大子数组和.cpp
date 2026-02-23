/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
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
// 贪心
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//        if (nums.size() == 1) {
//         return nums[0]; 
//        }  
//        int len = nums.size();  
//        int result = INT_MIN; 
//        int count = 0; 
//        for (int i = 0; i < len; i++) { 
//             if (count < 0) {
//                 count = 0; 
//             }    
//             count += nums[i]; 
//             result = max(count, result); 
//        } 
//        return result; 
//     }
// };


// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         if (nums.size() == 1) {
//             return nums[0]; 
//         } 
//         int result = INT_MIN; 
//         int curr = 0; 
//         for (int i = 0; i < nums.size(); i++) {
//             if (curr < 0) {
//                 curr = 0;  
//             }  
//             curr += nums[i]; 
//             result = max(curr, result); 
//         } 
//         return result; 
//     }
// };

// 动态规划
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0]; 
        } 
        vector<int> dp(nums.size(), 0);  
        dp[0] = nums[0];  
        int result = nums[0]; 
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);  
            if (result < dp[i]) {
                result = dp[i]; 
            }
        } 
        return result; 
    }
};
// @lc code=end

