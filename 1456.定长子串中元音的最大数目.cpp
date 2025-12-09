/*
 * @lc app=leetcode.cn id=1456 lang=cpp
 *
 * [1456] 定长子串中元音的最大数目
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
// class Solution {
// public: 

//     bool isValid(char c) {
//         return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
//                 c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
//     }

//     int maxVowels(string s, int k) {
//         int curr = 0; 
//         int i = 0; 
//         deque<char> d; 
//         for (i = 0; i < k; i++) {
//             d.push_back(s[i]); 
//             if (isValid(s[i])) {
//                 curr++; 
//             } 
//         } 
//         int max = curr; 
//         for (i = k; i < s.size(); i++) {
//             d.push_back(s[i]); 
//             if (isValid(d.back())) {
//                 curr++; 
//             } 
            
//             if (isValid(d.front())) {
//                 curr--;  
//             } 
//             d.pop_front(); 
//             max = max > curr ? max :curr; 
//         } 
//         return max; 
//     }
// };  




class Solution {
public: 

    bool isValid(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }

    int maxVowels(string s, int k) {
       int result = 0; 
       int curr = 0; 
       for (int i = 0; i < s.size(); i++) {
            if (isValid(s[i])) {
                curr++; 
            } 
            int left = i - k + 1; 
            if (left < 0) {
                continue; 
            } 
            result = max(result, curr); 
            if (result == k) {
                break; 
            } 
            if (isValid(s[left])) {
                curr--; 
            }
       } 
       return result; 
    }
}; 
// @lc code=end

