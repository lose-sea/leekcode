/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
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
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0]; 
    }
    int findMinArrowShots(vector<vector<int>>& points) { 
        int len = points.size();   
        if (len == 0) {
            return 0; 
        }
        sort(points.begin(), points.end(), cmp);  
        int result = 1; 
        for (int i = 1; i < len; i++) {
            if (points[i][0] > points[i - 1][1]) {
                result++; 
            } else {
                points[i][1] = min(points[i - 1][1], points[i][1]); 
            }
        } 
        return result; 
    }
};
// @lc code=end

