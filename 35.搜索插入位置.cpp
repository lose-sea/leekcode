/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include<iostream> 
#include<climits> 
#include<vector> 
#include<algorithm>
using namespace std; 
// @lc code=start
// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
        
//     }
// }; 

// 暴力
// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] == target) {
//                 return i; 
//             } else if (nums[i] > target) {
//                 return i; 
//             }
//         } 
//         return nums.size(); 
//     } 
// }; 





// 二分查找
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0; 
        int right = nums.size() - 1; 
        int ans = nums.size(); 
        while (left <= right) {
            int mid = left + (right - left) / 2;  
            if (target <= nums[mid]) {
                ans = mid;  
                right = mid - 1; 
            } else { 
                left = mid + 1; 
            }
        } 
        return ans; 
    }
}; 
// @lc code=end

