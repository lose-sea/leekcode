/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 灞辫剦鏁扮粍鐨勫嘲椤剁储寮�
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
    int peakIndexInMountainArray(vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i + 1] < arr[i]) {
                return i; 
            }
        } 
        return arr.size() - 1; 
    }
};
// @lc code=end

