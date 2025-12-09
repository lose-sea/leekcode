/*
 * @lc app=leetcode.cn id=3679 lang=cpp
 *
 * [3679] 使库存平衡的最少丢弃次数
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
class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int result = 0; 
        unordered_map<int, int> mp; 
        int lenth = 0; 
        int left = 0; 
        for (int i = 0; i < arrivals.size(); i++) { 
            if (mp[arrivals[i]] >= m) {
                result++; 
                arrivals[i] = -1; 
            } else {
                mp[arrivals[i]]++; 
            }
            int left = i - w + 1; 
            if (left >= 0) {
                mp[arrivals[left]]--; 
            }
        } 
        return result; 
    }
};
// @lc code=end

