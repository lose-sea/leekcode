/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
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
class Solution {
public:
    int rob(vector<int>& nums) { 
        if (nums.empty()) {
            return 0; 
        }
        int len = nums.size();  
        if (len == 1) {
            return nums[0]; 
        }
        vector<int> dp(len, 0); 
        dp[0] = nums[0]; 
        dp[1] = max(nums[0], nums[1]);  
        for (int i = 2; i < len; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]); 
        } 
        return dp[len - 1]; 
    }
};
// @lc code=end

