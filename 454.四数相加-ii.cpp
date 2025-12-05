/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */
#include<iostream> 
#include<vector> 
#include<unordered_set> 
#include<map> 
#include<unordered_map>
using namespace std; 
// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int num = 0; 
        unordered_map<int, int> mp1; 
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                int sum = nums1[i] + nums2[j]; 
                mp1[sum]++; 
            } 
        } 
        for (int a : nums3) {
            for (int b : nums4) {
                int temp = 0 - a - b; 
                if (mp1.find(temp) != mp1.end()) {
                    num += mp1.find(temp)->second; 
                }
            } 
        }
        return num; 
    }
};
// @lc code=end

