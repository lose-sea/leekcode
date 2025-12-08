/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
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
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0; 
        if (nums.size() == 1) {
            return true; 
        } 
        for (int i = 0; i <= cover; i++) {
            cover = max(cover, i + nums[i]); 
            if (cover >= nums.size() - 1) {
                return true; 
            }
        } 
        return false; 
    }
};
// @lc code=end

