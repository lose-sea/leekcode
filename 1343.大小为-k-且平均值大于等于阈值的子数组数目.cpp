/*
 * @lc app=leetcode.cn id=1343 lang=cpp
 *
 * [1343] 大小为 K 且平均值大于等于阈值的子数组数目
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
    
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int curr = 0; 
        int num = 0; 
        for (int i = 0; i < arr.size(); i++) {
            curr += arr[i]; 
            int left = i - k + 1; 
            if (left < 0) {
                continue; 
            }  
            if (curr >= threshold * k) {
                num++; 
            } 
            curr -= arr[left]; 
        } 
        return num; 
    }
};
// @lc code=end

