/*
 * @lc app=leetcode.cn id=1486 lang=cpp
 *
 * [1486] 数组异或操作
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
class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> nums(n, start);   
        int result = nums[0]; 
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = start + 2 * i; 
            result ^= nums[i];  
        } 
        return result; 
    }
};
// @lc code=end

