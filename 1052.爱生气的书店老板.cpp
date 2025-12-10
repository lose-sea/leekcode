/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 *
 * [1052] 爱生气的书店老板
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
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int result = 0; 
        int curr = 0; 
        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 1) {
                curr += customers[i]; 
            } 
            int left = i - minutes + 1; 
            if (left < 0) { 
                continue; 
            } 
            result = max(curr, result); 
            if (grumpy[left] == 1) {
                curr -= customers[left]; 
            } 
        } 
        int sum = 0; 
        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 0) {
                sum += customers[i]; 
            }
        } 
        result += sum; 
        return result;
    }
};
// @lc code=end

