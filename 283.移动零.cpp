/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include<iostream> 
#include<climits> 
#include<vector> 
#include<algorithm>
using namespace std; 
// @lc code=start 

// 会超时
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         if (nums.empty()) {
//             return; 
//         } 
//         int size = nums.size(); 
//         for (int i = 0; i < size; i++) { 
//             if (nums[i] == 0) {
//                 for (int j = i; j < size - 1; j++) {
//                     nums[j] = nums[j + 1]; 
//                 } 
//                 nums[size - 1] = 0;  
//                 i--; 
//             }
//         }
//     } 
// };




class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0; 
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                nums[left] = nums[right]; 
                left++; 
            }
        } 
        for (int i = left; i < nums.size(); i++) {
            nums[i] = 0; 
        } 
    } 
};
// @lc code=end

