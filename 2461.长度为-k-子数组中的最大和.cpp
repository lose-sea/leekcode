/*
 * @lc app=leetcode.cn id=2461 lang=cpp
 *
 * [2461] 长度为 K 子数组中的最大和
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
//     long long maximumSubarraySum(vector<int>& nums, int k) {

//         long long result = 0; 
//         long long curr = 0; 
//         int start = 0; 
//         unordered_set<int> set; 
//         for (int i = 0; i < nums.size(); i++) {
//             if (set.find(nums[i]) == set.end()) {
//                 curr += nums[i]; 
//                 set.insert(nums[i]); 
//             } else {
//                 while (set.find(nums[i]) != set.end()) {
//                     curr -= nums[start]; 
//                     set.erase(nums[start]);   
//                     start++; 
//                 }  
//                 set.insert(nums[i]); 
//                 curr += nums[i]; 
//             }
//             int left = i - k + 1; 
//             if (left < start) {
//                 continue; 
//             } 
//             result = max(result, curr); 
//             curr -= nums[left]; 
//             set.erase(nums[left]); 
//             start = left + 1; 
//         } 
//         return result; 
//     }
// };        

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long result = 0; 
        long long curr = 0; 
        unordered_map<int, int> mp; 
        for (int i = 0; i < nums.size(); i++) {
            curr += nums[i]; 
            mp[nums[i]]++; 
            int left = i - k + 1; 
            if (left < 0) {
                continue; 
            } 
            if (mp.size() == k) {
                result = max(result, curr); 
            } 
            curr -= nums[left]; 
            if (--mp[nums[left]] == 0) {
                mp.erase(nums[left]); 
            }
        } 
        return result; 
    }
}; 

    
// @lc code=end

