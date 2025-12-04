/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */
#include<iostream> 
#include<vector> 
#include<unordered_set> 
#include<unordered_map>
using namespace std; 
// @lc code=start 

// 数组哈希
// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> temp(100000, 0); 
//         for (int i = 0; i < nums1.size(); i++) {
//             temp.at(nums1[i])++; 
//         }  
//         vector<int> result; 
//         for (int i = 0; i < nums2.size(); i++) {
//             if (temp[nums2[i]] != 0) {
//                 result.push_back(nums2[i]); 
//                 temp[nums2[i]] = 0; 
//             } 
//         } 
//         return result; 
//     }
// };




class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) { 
        unordered_set<int> result;  
        unordered_set<int> nums_set(nums1.begin(), nums1.end()); 
        for (int i = 0; i < nums2.size(); i++) {
            if (nums_set.find(nums2[i]) != nums_set.end()) {
                result.insert(nums2[i]); 
            }
        } 
        return vector<int>(result.begin(), result.end()); 
    }
};


// @lc code=end

