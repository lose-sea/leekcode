/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
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
#include<numeric>  
using namespace std;
// @lc code=start
class Solution {
public: 
    static bool cmp(const vector<int>& e1, const vector<int>& e2) {
        if (e1[0] != e2[0]) {
            return e1[0] > e2[0];  
        } 
        return e1[1] < e2[1]; 
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int len = people.size(); 
        sort(people.begin(), people.end(), cmp);  
        vector<vector<int>> que; 
        for (int i = 0; i < len; i++) {
            int position = people[i][1]; 
            que.insert(que.begin() + position, people[i]); 
        }
        return que;  
    } 
};
// @lc code=end

