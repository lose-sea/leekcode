/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
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
using namespace std;  

// @lc code=start 
// // 贪心
// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         if (nums.size() == 2 && nums[0] != nums[1]) {
//             return 2; 
//         }  
//         if (nums.size() < 2) {
//             return nums.size(); 
//         }  
//         int result = 1; 
//         int prevdiff = 0; 
//         int currdiff = 0; 
//         for (size_t i = 0; i < nums.size() - 1; i++) {
//             currdiff = nums[i + 1] - nums[i]; 
//             if ((prevdiff <= 0 && currdiff > 0) || (prevdiff >= 0 && currdiff < 0)) {
//                 result++; 
//                 prevdiff = currdiff;  
//             } 
//         } 
//         return result;  
//     } 
// };

// 动态规划
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        size_t len = nums.size();  
        if (len < 2) {
            return len; 
        } 
        int dp_up = 1; 
        int dp_down = 1; 
        for (size_t i = 1; i < len; i++) {
            if (nums[i] > nums[i - 1]) {
                dp_up = dp_down + 1; 
            } else if (nums[i] < nums[i - 1]) {
                dp_down = dp_up + 1; 
            } 
        } 
        return max(dp_down, dp_up); 
    } 
};
// @lc code=end

