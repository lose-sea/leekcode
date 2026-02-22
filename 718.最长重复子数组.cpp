/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
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
#include<cmath> 
#include<deque>  
#include<numeric>
using namespace std; 
// @lc code=start


// class Solution {
// public:
//     int findLength(vector<int>& nums1, vector<int>& nums2) {
//         vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));  
//         int result = 0; 
//         for (int i = 1; i <= nums1.size(); i++) {
//             for (int j = 1; j <= nums2.size(); j++) {
//                 if (nums1[i - 1] == nums2[j - 1]) {
//                     dp[i][j] = dp[i - 1][j - 1] + 1; 
//                 } 
//                 result = max(dp[i][j], result); 
//             }
//         }
//         return result; 
//     }
// };


// // 滚动数组
// class Solution {
// public:
//     int findLength(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> dp(nums2.size() + 1, 0);  
//         int result = 0; 
//         for (int i = 1; i <= nums1.size(); i++) {
//             for (int j = nums2.size(); j > 0; j--) {
//                 if (nums1[i - 1] == nums2[j - 1]) {
//                     dp[j] = dp[j - 1] + 1; 
//                 } else {
//                     dp[j] = 0; 
//                 } 
//                 result = max(dp[j], result); 
//             }
//         }
//         return result; 
//     }
// };


class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;  
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0)); 
        for (int i = 1; i <= nums1.size(); i++) { 
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;  
                    result = max(dp[i][j], result); 
                }
            }
        }
        return result; 
    }
};
// @lc code=end

