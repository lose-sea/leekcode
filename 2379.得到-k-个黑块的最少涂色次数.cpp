/*
 * @lc app=leetcode.cn id=2379 lang=cpp
 *
 * [2379] 得到 K 个黑块的最少涂色次数
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
    int minimumRecolors(string blocks, int k) {
        int result = INT_MAX; 
        int curr = 0; 
        for (int i = 0; i < blocks.size(); i++) {
            if (blocks[i] == 'W') {
                curr++; 
            } 
            int left = i - k + 1; 
            if (left < 0) {
                continue; 
            }
            result = min(curr, result); 
            if (blocks[left] == 'W') {
                curr--; 
            } 
        } 
        return result; 
    }
};
// @lc code=end

