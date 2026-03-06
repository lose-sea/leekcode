/*
 * @lc app=leetcode.cn id=2586 lang=cpp
 *
 * [2586] 统计范围内的元音字符串数
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
    int vowelStrings(vector<string>& words, int left, int right) {
        int result = 0; 
        for (int i = left; i <= right; i++) {
            if ((words[i].front() == 'a' || words[i].front() == 'e' || words[i].front() == 'i' || words[i].front() == 'o' || words[i].front() == 'u') && (words[i].back() == 'a' || words[i].back() == 'e' || words[i].back() == 'i' || words[i].back() == 'o' || words[i].back() == 'u')) {
                result++; 
            }
        }  
        return result; 
    }
};
// @lc code=end

