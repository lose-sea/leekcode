/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
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
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         if (nums.size() == 1) {
//             return 0; 
//         } 
//         int currcover = 0; 
//         int result = 0; 
//         int nextcover = 0; 
//         for (int i = 0; i < nums.size(); i++) {
//             nextcover = max(nums[i] + i, nextcover); 
//             if (i == currcover) {
//                 result++; 
//                 currcover = nextcover; 
//                 if (currcover >= nums.size() - 1) {
//                     return result; 
//                 }
//             } 
//         }  
//         return result; 
//     } 
// };  

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0; 
        } 
        int result = 0; 
        int curr_distance = 0; 
        int next_distance = 0; 
        for (int i = 0; i < nums.size(); i++) {
            next_distance = max(next_distance, i + nums[i]);  
            if (i == curr_distance) {
                result++; 
                curr_distance = next_distance;  
                if (curr_distance >= nums.size() - 1) {
                    break; 
                } 
            } 
        } 
        return result; 
    } 
};
// @lc code=end

