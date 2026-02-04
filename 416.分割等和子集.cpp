/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
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
    bool canPartition(vector<int>& nums) {
        int len = nums.size(); 
        int sum = accumulate(nums.begin(), nums.end(), 0);  
        if (sum % 2 == 1) {
            return false; 
        } 
        int target = sum / 2; 
        vector<int> dp(sum, 0); 
        for (int i = 0; i < nums.size(); i++) {  
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]); 
            }
        } 
        if (dp[target] == target) {
            return true; 
        } 
        return false; 
    }
};
// @lc code=end

