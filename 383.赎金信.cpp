/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */
#include<iostream> 
#include<unordered_set> 
#include<vector> 
using namespace std;  
// @lc code=start
// class Solution {
// public:
//     bool canConstruct(string ransomNote, string magazine) {
//         vector<int> visited(256, 0); 

//         for (int i = 0; i < magazine.size(); i++) {
//             visited.at(magazine[i])++; 
//         } 
//         for (int i = 0; i < ransomNote.size(); i++) {
//             visited.at(ransomNote[i])--; 
//             if (visited[ransomNote[i]] < 0) {
//                 return false; 
//             } 
//         } 
//         return true; 
//     }
// }; 



// @lc code=end

