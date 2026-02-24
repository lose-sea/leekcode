/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
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



// // 暴力
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> result(nums1.size(), -1); 
//         for (int i = 0; i < nums1.size(); i++) {
//             for (int j = find(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin() + 1; j < nums2.size(); j++) {
//                 if (nums2[j] > nums1[i]) {
//                     result[i] = nums2[j];   
//                     break; 
//                 }
//             }
//         }
//         return result;  
//     }
// };


// 单调栈
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size(), -1); 
        stack<int> sk; 
        unordered_map<int, int> mp; 
        for (int i = 0; i < nums1.size(); i++) {
            mp[nums1[i]] = i; 
        }   
        sk.push(0);  
        for (int i = 1; i < nums2.size(); i++) {
            while (!sk.empty() && nums2[i] > nums2[sk.top()]) {
                if (mp.find(nums2[sk.top()]) != mp.end()) {
                    result[mp[nums2[sk.top()]]] = nums2[i]; 
                } 
                sk.pop(); 
            } 
            sk.push(i); 
        } 
        return result; 
    }
};
// @lc code=end

