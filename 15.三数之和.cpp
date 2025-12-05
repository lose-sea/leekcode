/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include<iostream> 
#include<set> 
#include<unordered_set> 
#include<vector> 
#include<algorithm>  
using namespace std; 
// @lc code=start
class Solution {
public: 
    vector<vector<int>> threeSum(vector<int>& nums) {  
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());  
        if (nums[0] > 0) {
            return result; 
        }
         
        int num = 0; 
        for (int i = 0; i < nums.size() - 2; i++) {  
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; 
            }
            int left = i + 1; 
            int right = nums.size() - 1; 
            while (left < right) {
                int sum = nums.at(i) + nums[left] + nums[right]; 
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]}); 
                    left++; 
                    right--; 
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++; 
                    } 
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--; 
                    } 
                } else if (sum < 0) {
                    left++; 
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++; 
                    } 
                } else { 
                    right--; 
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--; 
                    } 
                } 

            }
        } 
        return result; 
    }
};
// @lc code=end

