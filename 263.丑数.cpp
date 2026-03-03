/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
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
    bool isUgly(int n) { 
        if (n <= 0) {
            return false; 
        }
        vector<int> factor = {2, 3, 5}; 
        for (int num : factor) {
            while (n % num == 0) {
                n /= num; 
            }
        } 
        return n == 1; 
    }
};
// @lc code=end

