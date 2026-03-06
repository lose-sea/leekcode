/*
 * @lc app=leetcode.cn id=1422 lang=cpp
 *
 * [1422] 分割字符串的最大得分
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
class Solution {
public:
    int maxScore(string s) {
        int left = 0; 
        int right = 0; 
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                right++; 
            }
        }  
        int result = 0; 
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '1') {
                right--; 
            }  else {
                left++; 
            }
            result = max(left + right, result); 
        } 
        return result;
    }
};
// @lc code=end

