/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include<iostream> 
#include<unordered_set> 
#include<vector> 
using namespace std;  
// @lc code=start 

// 法一
// // 数组统计
// class Solution { 
// public: 
//     bool isAnagram(string s, string t) {  
//         if (s.size() != t.size()) { 
//             return false;  
//         } 
//         vector<int> visited; 
//         visited.resize(256, 0); 
//         for (int i = 0; i < s.size(); i++) {
//             visited.at(s.at(i))++; 
//         } 
//         for (int i = 0; i < t.size(); i++) {
//             if (visited.at(t.at(i)) == 0) {
//                 return false; 
//             } 
//             visited[t[i]]--; 
//         } 
//         return true; 
//     } 
// }; 


// // 法二
// // 排序
// class Solution { 
// public: 
    // bool isAnagram(string s, string t) {  
    //     if (s.size() != t.size()) { 
    //         return false;  
    //     } 
    //     sort(s.begin(), s.end()); 
    //     sort(t.begin(), t.end()); 
    //     return s == t; 
    // } 
// }; 



// 法三
// 哈希表
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
}; 






// @lc code=end

