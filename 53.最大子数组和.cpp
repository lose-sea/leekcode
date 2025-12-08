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
#include<numeric>
#include<string> 
#include<map> 
#include<stack> 
#include<deque> 
using namespace std; 
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {  
        int max = nums[0]; 
        int sum = INT_MIN; 
        for (int i = 0; i < nums.size(); i++) {
            if (sum < 0) { 
                sum = nums[i]; 
            }  else { 
                sum += nums[i];  
            } 
            max = max > sum ? max : sum;
        } 
        return max; 
    }
};
// @lc code=end

