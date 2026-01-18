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
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       if (nums.size() == 1) {
        return nums[0]; 
       }  
       int len = nums.size();  
       int result = INT_MIN; 
       int count = 0; 
       for (int i = 0; i < len; i++) { 
            if (count < 0) {
                count = 0; 
            }    
            count += nums[i]; 
            result = max(count, result); 
       } 
       return result; 
    }
};
// @lc code=end

