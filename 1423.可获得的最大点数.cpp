/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 *
 * [1423] 可获得的最大点数
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

// 寻找滑动窗口的最小值
// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {
//         int origin = accumulate(cardPoints.begin(), cardPoints.end(), 0); 
//         if (cardPoints.size() == k) {
//             return origin; 
//         } 
//         int minnum = INT_MAX; 
//         int curr = 0; 
//         int len = cardPoints.size() - k; 
//         for (int i = 0; i < cardPoints.size(); i++) {
//             curr += cardPoints[i]; 
//             int left = i - len + 1; 
//             if (left < 0) {
//                 continue;  
//             } 
//             minnum = min(minnum, curr); 
//             curr -= cardPoints[left]; 
//         } 
//         return origin - minnum; 
//     }
// };



class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {  
        int origin = reduce(cardPoints.begin(), cardPoints.end()); 
        int len = cardPoints.size() - k; 
        int s = reduce(cardPoints.begin(), cardPoints.begin() + len); 
        int minnum = s; 
        for (int i = len; i < cardPoints.size(); i++) {
            s += cardPoints[i] - cardPoints[i - len]; 
            minnum = min(s, minnum); 
        } 
        return origin - minnum; 
    }
};



// @lc code=end

