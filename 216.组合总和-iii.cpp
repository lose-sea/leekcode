/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
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

    vector<vector<int>> result; 
    vector<int> path; 
    void dfs(int n, int k, int sum, int startIndex) {
        if (path.size() == k) {
            if (n == sum) {
                result.push_back(path); 
            } 
            return; 
        } 
        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++) {
            path.push_back(i); 
            sum += i; 
            dfs(n, k ,sum, i + 1);  
            path.pop_back(); 
            sum -= i; 
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear(); 
        path.clear(); 
        dfs(n, k, 0, 1); 
        return result; 
    }
};
// @lc code=end

