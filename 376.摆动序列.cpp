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
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) { 
        if (nums.size() <= 1) {
            return nums.size(); 
        }
        int currdiff = 0; 
        int prevdiff = 0; 
        int result = 1;     
        for (int i = 0; i < nums.size() - 1; i++) {
            currdiff = nums[i + 1] - nums[i]; 
            if ((prevdiff <= 0 && currdiff >0) || (prevdiff >= 0 && currdiff < 0)) {
                result++; 
                prevdiff = currdiff; 
            } 
        } 
        return result; 
    }
};
// @lc code=end

