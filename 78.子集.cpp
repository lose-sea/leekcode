/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
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

    void backTracking(vector<int> nums, int startIndex) { 
        int len = nums.size(); 
        result.push_back(path); 
        if (startIndex >= nums.size()) { 
            return;  
        }  
        for (int i = startIndex; i < len; i++) { 
            path.push_back(nums[i]);  
            backTracking(nums, i + 1);  
            path.pop_back();  
        } 
    } 



    vector<vector<int>> subsets(vector<int>& nums) {
        backTracking(nums, 0); 
        return result; 
    }
};
// @lc code=end

