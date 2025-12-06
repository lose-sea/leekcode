/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
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
    class mycmp { 
    public: 
        bool operator()(const pair<int, int> p1, const pair<int, int> p2) {
            return p1.second > p2.second; 
        }
    }; 
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp; 
        int len = nums.size(); 
        for (int i = 0; i < len; i++) {
            mp[nums[i]]++; 
        } 
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycmp> q;  
        for (auto it = mp.begin(); it != mp.end(); it++) {
            q.push(*it);  
            if (q.size() > k) {
                q.pop(); 
            }
        } 
        vector<int> result(k); 
        for (int i = k - 1; i >= 0; i--) {
            result.at(i) = q.top().first; 
            q.pop(); 
        } 
        return result; 
    }
}; 
// @lc code=end

