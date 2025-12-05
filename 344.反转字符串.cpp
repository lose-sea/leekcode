/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */
#include<iostream> 
#include<set> 
#include<unordered_set> 
#include<vector> 
#include<algorithm>  
using namespace std; 
// @lc code=start
// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         for (int i = 0; i < s.size() / 2; i++) {
//             char temp = s[i]; 
//             s[i] = s[s.size() - 1 - i]; 
//             s[s.size() - 1 - i] = temp; 
//         } 
//     }
// };  

// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         reverse(s.begin(), s.end()); 
//     }
// }; 


class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0; 
        int right = s.size() - 1; 
        while (left < right) {
            swap(s[left], s[right]); 
            left++; 
            right--; 
        }
    }
}; 
// @lc code=end

