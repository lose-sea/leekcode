/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
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
#include<numeric>
using namespace std;
// @lc code=start
// class Solution {
// public:
//     int largestSumAfterKNegations(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end()); 
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] < 0 && k > 0) {
//                 nums[i] = -nums[i]; 
//                 k--; 
//             } else {
//                 break; 
//             }
//         } 
//         if (k > 0) {
//             sort(nums.begin(), nums.end()); 
//             if (k % 2 == 1) {
//                 nums[0] = -nums[0]; 
//             }
//         } 
//         int result = accumulate(nums.begin(), nums.end(), 0); 
//         return result; 
//     }
// };  

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) { 
        if (k == 0) {
            return accumulate(nums.begin(), nums.end(), 0); 
        }
        sort(nums.begin(), nums.end());  

        for (int i = 0; i < nums.size() && k > 0; i++) {
            if (nums[i] <= 0) {
                nums[i] = -nums[i];  
                k--; 
            } 
        }   
        sort(nums.begin(), nums.end()); 
        k %= 2;  
        if (k == 1) {
            nums[0] = -nums[0]; 
        } 
        return accumulate(nums.begin(), nums.end(), 0); 
    }
};
// @lc code=end

