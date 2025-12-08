/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
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

    vector<int> path; 
    vector<vector<int>> result; 
    void backTracking(vector<int>& candidates, int target, int startIndex, int currsum) {
        if (currsum == target) {
            result.push_back(path); 
        }  
        unordered_set<int> uset; 
        for (int i = startIndex; i < candidates.size(); i++) {
            if (currsum + candidates[i] > target) {
                break; 
            }  
            if (uset.find(candidates[i]) != uset.end()) {
                continue; 
            } 
            uset.insert(candidates[i]); 
            path.push_back(candidates[i]); 
            backTracking(candidates, target, i + 1, currsum + candidates[i]); 
            path.pop_back(); 
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) { 
        sort(candidates.begin(), candidates.end()); 
        backTracking(candidates, target, 0, 0); 
        return result; 
    }
};
// @lc code=end

