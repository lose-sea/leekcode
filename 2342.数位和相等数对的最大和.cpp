/*
 * @lc app=leetcode.cn id=2342 lang=cpp
 *
 * [2342] 数位和相等数对的最大和
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
#include<numeric>
#include<deque> 
using namespace std; 
// @lc code=start
// class Solution {
// public: 

//     int sumOfNum(int num) { 
//         int result; 
//         while (num > 0) {
//             result += num % 10;
//             num /= 10; 
//         } 
//         return result; 
//     }
//     int maximumSum(vector<int>& nums) {
//         vector<int> sum; 
//         for (int i = 0; i < nums.size(); i++) {
//             sum.push_back(sumOfNum(nums[i])); 
//         }  
//         int result = -1; 
//         int curr = 0; 
//         for (int i = 0; i < sum.size(); i++) {
//             for (int j = 0; j < sum.size(); j++) {
//                 if (i != j && sum[i] == sum[j]) {
//                     curr = nums[i] + nums[j]; 
//                     result = max(curr, result); 
//                 }
//             }
//         } 
//         return result; 
//     }
// };



class Solution {
public: 
    int sumOfNum(int num) { 
        int result; 
        while (num > 0) {
            result += num % 10;
            num /= 10; 
        } 
        return result; 
    }
    int maximumSum(vector<int>& nums) {
        vector<int> sum; 
        for (int i = 0; i < nums.size(); i++) {
            sum.push_back(sumOfNum(nums[i])); 
        }  
        int result = -1; 
        int curr = 0; 
        unordered_map<int, int> mp; 
        for (int i = 0; i < sum.size(); i++) {
            if (mp.find(sum[i]) != mp.end()) {
                curr = nums[i] + mp[sum[i]]; 
                mp[sum[i]] = max(mp[sum[i]], nums[i]); 
                result = max(result, curr); 
            } else {
                mp[sum[i]] = nums[i]; 
            }
            
        } 
        return result; 
    }
};
// @lc code=end

