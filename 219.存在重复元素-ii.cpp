/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
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
    bool containsNearbyDuplicate(vector<int>& nums, int k) { 
        int len = nums.size(); 
        unordered_map<int, int> mp; 
        for (int i = 0; i < len; i++) { 
            if (mp.find(nums[i]) != mp.end()) {
                return true; 
            } 
            mp[nums[i]] = i;  
            int left = i - k; 
            if (left < 0) {
                continue; 
            } 
            mp.erase(nums[left]);     
        } 
        return false; 
    }
};
// @lc code=end

