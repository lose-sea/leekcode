/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
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

    vector<vector<string>> result; 
    vector<string> path; 


    bool isPalindrome(string s, int startIndex, int end) {
        for (int i = startIndex, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false; 
            } 
        } 
        return true; 
    }



    void backtracking(const string& s, int startIndex) {
        if (startIndex >= s.size()) {
            result.push_back(path); 
            return; 
        } 
        for (int i = startIndex; i < s.size(); i++) {
            if (isPalindrome(s, startIndex, i)) {
                string str = s.substr(startIndex, i - startIndex + 1); 
                path.push_back(str); 
            } else {
                continue; 
            } 
            backtracking(s, i + 1);
            path.pop_back();
        } 
    } 

    vector<vector<string>> partition(string s) {
        backtracking(s, 0); 
        return result; 
    } 
};
// @lc code=end

