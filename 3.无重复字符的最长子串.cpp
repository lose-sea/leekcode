/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
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
//     int lengthOfLongestSubstring(string s) {
//         int result = 0; 
//         int curr =  0; 
//         int left = 0; 
//         unordered_map<char, int> mp; 
//         for (int i = 0; i < s.size(); i++) { 
//             curr++; 
//             if (mp[s[i]] == 0) {
//                 mp[s[i]] = 1; 
//                 result = max(result, curr); 
//             } else {
//                 while (mp[s[i]] == 1) {
//                     mp[s[left++]] = 0; 
//                     curr--; 
//                 }
//                 mp[s[i]] = 1; 
//             } 
//         } 
//         return result; 
//     }
// }; 





class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0; 
        int curr = 0; 
        int result = 0;  
        int len = s.size(); 
        unordered_set<char> set;  
        for (int i = 0; i < len; i++) {
            char c = s[i]; 
            while (set.count(c)) {
                set.erase(s[left]); 
                left++; 
            } 
            set.insert(c); 
            result = max(result, i - left + 1); 
        } 
        return result; 
    }
};
// @lc code=end

