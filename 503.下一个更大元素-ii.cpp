/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
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
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size(), -1); 
        stack<int> sk; 
        sk.push(0);    
        for (int i = 1; i < nums.size() * 2; i++) {
            while (!sk.empty() && nums[i % nums.size()] > nums[sk.top()]) {
                result[sk.top()] = nums[i % nums.size()]; 
                sk.pop(); 
            } 
            sk.push(i % nums.size());  
        }
        return result; 
    }
};
// @lc code=end

