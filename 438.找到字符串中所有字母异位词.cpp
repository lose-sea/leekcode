/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

#include <iostream>
#include <queue>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {  
        if (s.size() != t.size()) { 
            return false;  
        }  
        vector<int> table(26, 0); 
        for (auto& ch : s) {
            table [ch - 'a']++; 
        } 
        for (auto& ch : t) {
            table[ch - 'a']--;  
            if (table[ch - 'a'] < 0) {
                return false; 
            }
        }  
        return true; 
    } 
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) {
            return {};
        }
        vector<int> pos;
        for (int i = 0; i <= s.size() - p.size(); i++) {
            string temp = s.substr(i, p.size());
            if (isAnagram(temp, p)) {
                pos.emplace_back(i);
            }
        }
        return pos;
    }
};
// @lc code=end

