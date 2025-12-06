/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
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
// class Solution {
// public: 
//     vector<vector<int>> result; 
//     vector<int> path;  

//     void backtracking(int n, int k, int startIndex) {
//         if (path.size() == k) {
//             result.push_back(path); 
//             return; 
//         } 
//         for (int i = startIndex; i <= n; i++) {
//             path.push_back(i); 
//             backtracking(n, k, i + 1); 
//             path.pop_back(); 
//         } 
//     }



//     vector<vector<int>> combine(int n, int k) {  
//         result.clear(); 
//         path.clear(); 
//         backtracking(n, k, 1); 
//         return result; 
//     }
// };  



//优化
class Solution {
public: 
    vector<vector<int>> result; 
    vector<int> path;  

    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path); 
            return; 
        } 
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i); 
            backtracking(n, k, i + 1); 
            path.pop_back(); 
        } 
    }

    vector<vector<int>> combine(int n, int k) {  
        result.clear(); 
        path.clear(); 
        backtracking(n, k, 1); 
        return result; 
    }
};

// @lc code=end

