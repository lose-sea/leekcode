/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
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

    vector<vector<int>> result; 
    vector<int> path; 

    void backTracking(const vector<int>& nums, int startIndex) {
        if (path.size() >= 2) {
            result.push_back(path);
        }
        unordered_set<int> uset;  // 使用set对本层元素进行去重
        for (int i = startIndex; i < nums.size(); i++) { 
            if ((!path.empty() && nums[i] < path.back()) || uset.find(nums[i]) != uset.end()) {
                continue; 
            } 
            uset.insert(nums[i]); 
            path.push_back(nums[i]); 
            backTracking(nums, i + 1); 
            path.pop_back(); 
        }
    } 
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if (nums.size() < 2) {
            return result; 
        } 
        backTracking(nums, 0); 
        return result; 
    }
}; 
// @lc code=end

