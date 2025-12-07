/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
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
    vector<int> path; 
    vector<vector<int>> result; 


    void backTracking(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) { 
            result.push_back(path); 
            return; 
        }  
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue; 
            } 
            used[i] = true; 
            path.push_back(nums[i]); 
            backTracking(nums, used); 
            path.pop_back(); 
            used[i] = false; 
        } 
    } 

    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) {
            return {}; 
        } 
        vector<bool> used(nums.size(), false); 
        backTracking(nums, used); 
        return result; 

    }
};

// @lc code=end

