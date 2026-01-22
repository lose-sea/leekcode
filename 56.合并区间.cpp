/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
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
class Solution {
public: 
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0]; 
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len = intervals.size(); 
        if (len == 1) {
            return intervals; 
        } 
        sort(intervals.begin(), intervals.end(), cmp); 
        vector<vector<int>> result;   
        int start = intervals.front()[0]; 
        int end = intervals[0][1];  
        for (int i = 1; i < len; i++) {
            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]); 
            } else {
                result.push_back({start, end});  
                start = intervals[i][0];  
                end = intervals[i][1]; 
            }
        }  
        result.push_back({start, end}); 
        return result; 
    }
};
// @lc code=end

