/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
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
// @lc code=startm 
class NumArray {  
public: 
    vector<int> sum; 
    NumArray(vector<int>& nums) { 
        sum.resize(nums.size() + 1);  
        for (int i = 0; i < nums.size(); i++)  {
            sum[i + 1] = sum[i] + nums.at(i); 
        }
    }
     
    int sumRange(int left, int right) {
        return sum[right + 1] - sum[left]; 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

