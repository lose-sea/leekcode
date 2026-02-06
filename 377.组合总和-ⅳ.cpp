/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */
#include<iostream> 
#include<set> 
#include<unordered_set> 
#include<unordered_map>
#include<vector> 
#include<algorithm>   
#include<queue>   
#include<cmath>
#include<string> 
#include<cstdint>
#include<map> 
#include<stack> 
#include<deque>  
#include<numeric>  
using namespace std; 
// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint64_t> dp(target + 1, 0); 
        dp[0] = 1; 
        for (int i = 0; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i - nums[j] >= 0) {
                    dp[i] += dp[i - nums[j]]; 
                }
            }
        } 
        return dp[target]; 
    }
};
// @lc code=end

