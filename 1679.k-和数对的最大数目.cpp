/*
 * @lc app=leetcode.cn id=1679 lang=cpp
 *
 * [1679] K 和数对的最大数目
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
    int maxOperations(vector<int>& nums, int k) { 
        int len = nums.size(); 
        sort(nums.begin(), nums.end()); 
        int left  = 0; 
        int right = len - 1;  
        int result = 0; 
        while (left < right) { 
            int sum = nums[left] + nums[right]; 
            if (nums[left] + nums[right] == k) {
                result++; 
                right--; 
                left++; 
            } else if (sum < k) {
                left++;                

            } else { 
                right--; 
            }
        } 
        return result;  
    }
};
// @lc code=end

