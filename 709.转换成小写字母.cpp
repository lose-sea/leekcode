/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
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
    string toLowerCase(string s) {
        int len = s.size(); 
        for (int i = 0; i < s.size(); i++) {
            // if (s[i] >= 'A' && s[i] <= 'Z') {
            //     s[i] += 32; 
            // } 
            if (isupper(s[i])) {
                s[i] += 32; 
            }
        } 
        return s; 
    }
};
// @lc code=end

