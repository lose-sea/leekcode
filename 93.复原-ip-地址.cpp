/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
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
    vector<string> result; 

    bool isValid(const string& s, int startIndex, int end) { 
        if (startIndex > end) {
            return false; 
        }
        int sum = 0; 
        if (s.at(startIndex) == '0' && startIndex != end) {
            return false; 
        }
        for (int i = startIndex; i <= end; i++) { 
            sum = sum * 10 + (s[i] - '0');  
          
            if (sum > 255 || sum < 0) {
                return false;
            }
                 
        } 
        return true; ; 
    }  

    void backTracking(string s, int startIndex, int pointSum) {
        if (pointSum == 3) {
            if (isValid(s, startIndex, s.size() - 1)) {
                result.push_back(s); 
            } 
            return; 
        } 
        for (int i = startIndex; i < s.size(); i++) {
            if (isValid(s, startIndex, i)) {
                s.insert(s.begin() + i + 1, '.'); 
                pointSum++; 
                backTracking(s, i + 2, pointSum); 
                pointSum--; 
                s.erase(s.begin() + i + 1); 
            } else {
                break; 
            }
        } 

    } 

    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12) {
            return result; 
        }
        backTracking(s, 0, 0); 
        return result; 
    }
}; 
// @lc code=end

