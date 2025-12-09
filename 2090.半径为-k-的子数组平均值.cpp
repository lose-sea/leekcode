/*
 * @lc app=leetcode.cn id=2090 lang=cpp
 *
 * [2090] 半径为 k 的子数组平均值
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
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> result(nums.size(), -1); 
        long long s = 0; 
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];  
            if (i < 2 * k) {
                continue; 
            } 
            result[i - k] = s / (2 * k + 1); 
            s -= nums[i - 2 * k]; 
        } 
        return result; 
    }
};
// @lc code=end

