/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include<iostream> 
#include<set> 
#include<unordered_set> 
#include<vector> 
#include<algorithm>   
#include<queue>  
#include<string>
#include<stack> 
#include<deque> 
using namespace std; 
// @lc code=start 

// 暴力  (会超时)
// class Solution {
// public: 
//     int getMax(deque<int> q) { 
//         int max = q[0]; 
//         for (int i = 0; i < q.size(); i++) {
//             max = max > q[i] ? max : q[i];  
//         } 
//         return max; 
//     }
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {  
//         int len = nums.size(); 
//         int max = nums[0]; 
//         vector<int> result; 
//         deque<int> q; 
//         int i = 0; 
//         for (i = 0; i < k; i++) {
//             q.push_back(nums[i]); 
//             max = max > nums[i] ? max : nums[i]; 
//         } 
//         result.push_back(max);
//         for (; i < len; i++) {
//             max = max > nums[i] ? max : nums[i]; 
//             q.push_back(nums[i]); 
//             q.pop_front(); 
//             result.push_back(getMax(q)); 
//         } 
//         return result; 
//     }
// };  





// 单调队列
class Solution {
public: 

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {  
        int len = nums.size(); 
        int max = nums[0]; 
        vector<int> result; 
        deque<int> q;  
        for (int i = 0; i < k; i++) { 
           
            while (!q.empty() && q.back() < nums[i]) {
                q.pop_back(); 
            }  
            q.push_back(nums[i]);  
        } 
        result.push_back(q.front()); 
        for (int i = k; i < len; i++) {
            while (!q.empty() && q.back() < nums[i]) {
                q.pop_back(); 
            } 
            q.push_back(nums[i]);
            if (nums[i - k] == q.front()) {
                q.pop_front(); 
            }
            
            result.push_back(q.front()); 
        }
        return result; 
    }
};  
// @lc code=end

