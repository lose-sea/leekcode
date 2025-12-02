/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
        
//     }
// };
#include<iostream> 
#include<climits> 
#include<vector> 
#include<algorithm>
using namespace std; 

// // 暴力  （会超时）
// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int size = 0; 
//         int sum = 0; 
//         int n = 1000000; 
//         for (int start = 0; start < nums.size(); start++) {
//             for (int j = start; sum < target && j < nums.size(); j++) {
//                 size++; 
//                 sum += nums[j]; 
//             } 
//             if (sum >= target) {
//                 n = min(size, n);
//             }
//             size = 0; 
//             sum = 0;
//         }  
//         if (n == 1000000) {
//             return 0; 
//         }
//         return n; 
//     }
// }; 





// // 滑动窗口一
// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int left = 0; 
//         int right = 0; 
//         int minlen = INT_MAX; 
//         int sum = 0; 
//         while (right < nums.size()) {
//             while (sum < target && right < nums.size()) {
//                 sum += nums[right]; 
//                 right++; 
//             }  
//             if (sum >= target) {
//                 minlen = min(right - left, minlen);
//             }
//             while (sum >= target) {
//                 sum -= nums[left];  
//                 left++; 
//                 if (sum >= target) {
//                     minlen = min(right - left, minlen);
//                 }
//             } 
//         }  
//         if (minlen == INT_MAX) {
//             return 0; 
//         }
//         return minlen; 
//     }
// };


// 滑动窗口二
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT_MAX; 
        int i = 0; 
        int size = 0; 
        int sum = 0; 
        for (size_t j = 0; j < nums.size(); j++) {
            sum += nums[j]; 
            while (sum >= target) {
                size = j - i + 1; 
                len = min(size, len); 
                sum -= nums[i++]; 
            }
        }
        return len == INT_MAX ? 0 : len; 
    } 
};


// @lc code=end

