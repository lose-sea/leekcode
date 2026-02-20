/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
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
    int robRange(vector<int>& nums, int start, int end) {
        if (start == end) {
            return nums[start];  
            } 
            vector<int> dp(nums.size(), 0); 
            dp[start] = nums[start]; 
            dp[start + 1] = max(nums[start + 1], nums[start]); 
            for (int i = start + 2; i <= end; i++) {
                dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]); 
            }  
            return dp[end]; 
        } 
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0]; 
        }  
        int result1 = robRange(nums, 0, nums.size() - 2); 
        int result2 = robRange(nums, 1, nums.size() - 1);  
        return max(result1, result2); 
    } 
};
// @lc code=end

