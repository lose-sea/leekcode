/*
 * @lc app=leetcode.cn id=1534 lang=cpp
 *
 * [1534] 统计好三元组
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
    int countGoodTriplets(vector<int>& nums, int a, int b, int c) { 
        int result = 0; 
        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i + 1; j < nums.size() - 1; j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (abs(nums[i] - nums[j]) <= a && abs(nums[j] - nums[k]) <= b && abs(nums[i] - nums[k]) <= c) {
                        result++; 
                    }
                }
            }
        } 
        return result; 
    }
};
// @lc code=end

