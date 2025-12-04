/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include<iostream> 
#include<vector> 
#include<unordered_set> 
#include<unordered_map>
using namespace std; 
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;  
        vector<int> result; 
        for (int i = 0; i < nums.size(); i++) {
            int remain = target - nums[i]; 
            if (mp.find(remain) != mp.end()) {
                result.push_back(mp.find(remain)->second); 
                result.push_back(i); 
                return result;  
            } else {
                mp.insert(make_pair(nums[i], i)); 
            }
        } 
        return result; 
    }
};
// @lc code=end

