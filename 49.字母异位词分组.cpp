/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include<iostream> 
#include<vector> 
#include<algorithm>
#include<unordered_map>
using namespace std; 
// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp; 
        for (string& str : strs) { 
            string temp = str; 
            sort(temp.begin(), temp.end()); 
            mp[temp].emplace_back(str); 
        } 
        vector<vector<string>> ans; 
        for (auto it = mp.begin(); it != mp.end(); it++) {
            ans.emplace_back(it->second); 
        } 
        return ans; 
    }
};
// @lc code=end

