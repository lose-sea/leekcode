/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
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
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int result = INT_MIN; 
        int curr = 0; 
        for (int i = 0; i < nums.size(); i++) {
            curr += nums.at(i); 
            int left = i - k + 1; 
            if (left < 0) {
                continue; 
            }   
            result = max(curr, result); 
            curr -= nums[left];   
        } 
        return (double)result / k; 
    }
};
// @lc code=end

