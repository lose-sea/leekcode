/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
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
// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int len = ratings.size(); 
//         if (len == 1) {
//             return 1; 
//         } 
//         map<int,pair<int, int>> mp;  
//         for (int i = 0; i < len; i++) {
//             mp[i].first = ratings[i]; 
//             mp[i].second = 1; 
//         }  
//         // 和后一个比较
//         for (int i = len - 2; i >= 0; i--) {
//             if (mp[i].first > mp[i + 1].first) {
//                 mp[i].second = mp[i + 1].second + 1; 
//             }
//         }  
//         // 和前一个比较
//         for (int i = 1; i < len; i++) {
//             if (mp[i].first > mp[i - 1].first && mp[i].second <= mp[i - 1].second) {
//                 mp[i].second = mp[i - 1].second + 1; ; 
//             }
//         } 
//         int result = 0; 
//         for (int i = 0; i < len; i++) {
//             result += mp[i].second; 
//         } 
//         return result; 
//     }
// }; 

class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size(); 
        if (len == 1) {
            return 1; 
        } 
        vector<int> candyVec(len, 1);  
        // 与下前一个比较
        for (int i = 1; i < len; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candyVec[i] = candyVec[i - 1] + 1; 
            }
        }  
        // 与后一个比较 
        for (int i = len - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] && candyVec[i] <= candyVec[i + 1]) {
                candyVec[i] = candyVec[i + 1] + 1; 
            }
        } 
        int result = 0; 
        for (int i = 0; i < len; i++) {
            result += candyVec[i]; 
        } 
        return result; 
    }
};
// @lc code=end

