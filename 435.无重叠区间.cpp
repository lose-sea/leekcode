/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
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
#include<numeric>  
using namespace std; 
// @lc code=start 
// 根据右边界排序
// class Solution {
// public:  
//     // 右边界排序
//     static bool cmp(const vector<int>& a, const vector<int>& b) {
//         return a[1] < b[1]; 
//     }
//     int eraseOverlapIntervals(vector<vector<int>>& intervals) { 
//         int len = intervals.size(); 
//         if (len < 2) {
//             return 0; 
//         } 
//         sort(intervals.begin(), intervals.end(), cmp);   
//         int count = 1; // 无重叠非交叉区间  
//         int end = intervals[0][1]; 
//         for (int i = 1; i < len; i++) {
//             if (end <= intervals[i][0]) {
//                 end = intervals[i][1];  
//                 count++; 
//             }
//         } 
//         return len - count; 
//     } 
// }; 
// 根据左边界排序
class Solution {
public:  
    // 左边界排序
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0]; 
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) { 
        int len = intervals.size(); 
        if (len < 2) {
            return 0; 
        } 
        sort(intervals.begin(), intervals.end(), cmp);   
        int count = 0;  // 记录重叠区间 
        int end = intervals[0][1]; 
        for (int i = 1; i < len; i++) {
            if (intervals[i][0] >= end) {
                end = intervals[i][1]; 
            } else {
                end = min(end, intervals[i][1]);  
                count++; 
            }
        }  
        return count; 
    } 
}; 
// @lc code=end

