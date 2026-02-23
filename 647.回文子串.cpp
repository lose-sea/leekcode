/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
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
#include<cmath> 
#include<deque>  
#include<numeric>
using namespace std; 
// @lc code=start  

// // 暴力枚举
// class Solution {
// public: 
//     bool isPalindrome(const string& s) {
//         if (s.empty() || s.size() == 1) {
//             return true; 
//         } 
//         int left = 0; 
//         int right = s.size() - 1; 
//         while (left < right) {
//             if (s[left] != s[right]) {
//                 return false; 
//             } 
//             left++; 
//             right--; 
//         } 
//         return true; 
//     }
//     int countSubstrings(string s) { 
//         int result = 0; 
//         for (int i = 0; i < s.size(); i++) { 
//             for (int j = 1; j <= s.size() - i; j++) {
//                 string str = s.substr(i, j); 
//                 if (isPalindrome(str)) {
//                     result++; 
//                 } 
//             }
//         } 
//         return result; 
//     }
// };

// class Solution {
// public:
//     int countSubstrings(string s) { 
//         if (s.size() == 1 || s.empty()) {
//             return 1; 
//         }
//         int result = 0; 
//         vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false)); 
//         for (int i = s.size() - 1; i >= 0; i--) {
//             for (int j = i; j < s.size(); j++) {
//                 if (s[i] == s[j]) {
//                     if (j - i <= 1) {
//                         dp[i][j] = true; 
//                         result++; 
//                     } else if (dp[i + 1][j - 1]) {
//                         dp[i][j] = true; 
//                         result++; 
//                     }
//                 }
//             }
//         }
//         return result; 
//     }
// };



class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            result += extend(s, i, i, s.size()); // 以i为中心
            result += extend(s, i, i + 1, s.size()); // 以i和i+1为中心
        }
        return result;
    }
    int extend(const string& s, int i, int j, int n) {
        int res = 0;
        while (i >= 0 && j < n && s[i] == s[j]) {
            i--;
            j++;
            res++;
        }
        return res;
    }
};
// @lc code=end

