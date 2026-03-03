/*
 * @lc app=leetcode.cn id=1470 lang=cpp
 *
 * [1470] 重新排列数组
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
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result(n * 2, 0); 
        for (int i = 0; i < n; i++) {
            result[i * 2] = nums[i]; 
            result[i * 2 + 1] = nums[i + n]; 
        } 
        return result; 
    }
};
// @lc code=end

