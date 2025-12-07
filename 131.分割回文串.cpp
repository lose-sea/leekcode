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
    bool isreverse(const string& s, int start, int end) {
        int len = s.size(); 
        for (int i = start, j = end; i <= j; i++, j--) {
            if (s[i] != s[j]) {
                return false; 
            }
        }
        return true; 
    }  

    vector<string> path; 
    vector<vector<string>> result; 

    void dfs(string s, int startIndex) {
        if (startIndex >= s.size()) {
            result.push_back(path); 
        } 
        for (int i = startIndex; i  < s.size(); i++) {
            if (isreverse(s, startIndex, i)) { 
                string str = s.substr(startIndex, i - startIndex + 1); 
                path.push_back(str); 
            } else {
                continue; 
            }  
            dfs(s, i + 1);  
            path.pop_back(); 
        }  
    } 

    vector<vector<string>> partition(string s) {
        dfs(s, 0); 
        return result; 
    }
};
// @lc code=end

