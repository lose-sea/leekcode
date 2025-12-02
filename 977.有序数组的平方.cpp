/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */
#include<iostream> 
#include<climits> 
#include<vector> 
#include<algorithm>
#include<cmath>
using namespace std; 
// @lc code=start
// class Solution { 
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
        
//     }
// };

// // 暴力排序
// class Solution { 
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
//             *it = pow(*it, 2); 
//         } 
//         sort(nums.begin(), nums.end());  
//         return nums; 
//     }
// };


// 双指针
class Solution { 
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int k = nums.size() - 1; 
        vector<int>result(nums.size(), 0);  
        for (int i = 0, j = nums.size() - 1; i <= j; ) {
            if (nums[i] * nums[i] < nums[j] * nums[j]) {
                result[k--] = nums[j] * nums[j]; 
                j--; 
            } else { 
                result[k--] = nums[i] * nums[i]; 
                i++; 
            }
        }
        return result; 
    }
};
// @lc code=end

