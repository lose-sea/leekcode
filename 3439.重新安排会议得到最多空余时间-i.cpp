/*
 * @lc app=leetcode.cn id=3439 lang=cpp
 *
 * [3439] 重新安排会议得到最多空余时间 I
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
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size(); 
        int curr = 0; 
        int result = 0; 
        for (int i = 0; i < startTime.size(); i++) {
            curr += endTime[i] - startTime[i]; 
            int left = i <= k - 1 ? 0 : endTime[i - k]; 
            int right = i == n - 1 ? eventTime : startTime[i + 1]; 
            result = max(result, right - left - curr); 
            if (i >= k - 1) {
                curr -= endTime[i - k + 1] - startTime[i - k + 1]; 
            }  
        } 
        return result; 
    }
};
// @lc code=end

