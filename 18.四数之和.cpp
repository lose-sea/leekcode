/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
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
    vector< vector<int> > fourSum(vector<int>& nums, int target) {  
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> result; 
        if (nums.size() < 4) {
            return result ;            
        }
        for (int i = 0; i < nums.size() - 3; i++) { 
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; 
            }
            for (int j = i + 1; j < nums.size() - 2; j++) { 
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue; 
                } 
                long long temp = (long long)target - nums[i] - nums[j]; 
                int left = j + 1; 
                int right = nums.size() - 1; 
                while (left < right) {
                    long long sum = (long long)nums[left] + nums[right]; 
                    if (sum == temp) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]}); 
                        left++; 
                        right--;  
                        while (left < right && (long)nums[left] == nums[left - 1]) {
                        left++; 
                        } 
                        while (left < right && nums[right] == nums[right + 1]) {
                            right--; 
                        } 
                    } else if (sum < temp) {
                        left++; 
                    } else {
                        right--; 
                    }
                }
            }
        }
        return result; 
    }
}; 
// @lc code=end

