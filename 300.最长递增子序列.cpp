/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
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
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) { 
        if (nums.size() <= 1) {
            return nums.size(); 
        }
        vector<int> dp(nums.size(), 1);   
        int result = 0; 
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1); 
                }
            } 
            if (result < dp[i]) {
                result = dp[i]; 
            }
        } 
        return result; 
    }
};
// @lc code=end

