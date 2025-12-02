/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

#include<iostream> 
#include<climits> 
#include<vector> 
#include<algorithm>
using namespace std; 
// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) { 
        int left = 0;      // 左边界 
        int maxnum = 0;   // 最多个数
        int kind = 0;       // 水果的种类  
        vector<int> intCount(fruits.size()); // 记录水果的种类
        for (int i = 0; i < fruits.size(); i++) {
            if (intCount[fruits[i]] == 0) {
                kind++; 
            } 
            intCount[fruits[i]]++; 
            while (kind > 2) {
                intCount[fruits[left]]--; 
                if (intCount[fruits[left]] == 0) {
                    kind--; 
                }  
                left++; 
            } 
            maxnum = max(maxnum, i - left + 1); 
        } 
        return maxnum; 
    }
}; 
// @lc code=end

