/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
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
#include<numeric>  
using namespace std; 
// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int len = s.size();  
        vector<int> result;   
        int curr = 0;    
        int start = s.find(s[0]); 
        int end = s.rfind(s[0]); 
        for (int i = 0; i < len; i++) { 
            if (s.rfind(s[i]) > end) {
                end = s.rfind(s[i]); 
            }
            if (i == end) {
                result.emplace_back(end - start + 1); 
                start = i + 1; 
            } 
        }   
        return result; 
    }
};
// @lc code=end

