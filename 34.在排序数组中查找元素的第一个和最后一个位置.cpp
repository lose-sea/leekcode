/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include<iostream> 
#include<vector> 
using namespace std; 
// @lc code=start
// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
        
//     }
// }; 


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0; 
        int right = nums.size() - 1;  
        int front = -1; 
        int last = -1; 
        while (left <= right) {
            if (nums.at(left) == target) {
                front = left; 
                break; 
            } 
            left++; 
        } 
        while (left <= right) {
            if (nums.at(right) == target) {
                last = right; 
                break; 
            } 
            right--; 
        } 
        vector<int> result(2, -1); 
        if (left != -1) {
            result = {front, last}; 
        } 
        return result; 
    }
};
// @lc code=end

