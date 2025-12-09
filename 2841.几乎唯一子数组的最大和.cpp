/*
 * @lc app=leetcode.cn id=2841 lang=cpp
 *
 * [2841] 几乎唯一子数组的最大和
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
    long long maxSum(vector<int>& nums, int m, int k) {
        long long result = 0; 
        long long curr = 0; 
        unordered_map<int, int> mp; 
        for (int i = 0; i < nums.size(); i++) {
            curr += nums[i]; 
            mp[nums[i]]++; 
            int left = i - k + 1; 
            if (left < 0) {
                continue; 
            } 
            if (mp.size() >= m) {
                result = max(result, curr); 
            } 
            int out = nums[left]; 
            curr -= nums[left]; 
            if (--mp[nums[left]] == 0) {
                mp.erase(nums[left]); 
            }
        } 
        return result; 
    }
}; 





// @lc code=end

