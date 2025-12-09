/*
 * @lc app=leetcode.cn id=624 lang=cpp
 *
 * [624] 数组列表中的最大距离
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
#include<numeric>
#include<deque> 
using namespace std; 
// @lc code=start
// class Solution {
// public:
//     int maxDistance(vector<vector<int>>& arrays) { 
//         vector<int> minnum; 
//         vector<int> maxnum; 
//         int size = arrays.size(); 
//         for (int i = 0; i < size; i++) {
//             int min_n = arrays[i][0]; 
//             int max_n = arrays[i][arrays[i].size() - 1]; 
//             minnum.push_back(min_n); 
//             maxnum.push_back(max_n);  
//         } 
//         int result = 0; 
//         for (int i = 0; i < size; i++) {
//             minnum[i] = maxnum[i]; 
//             for (int j = 0; j < size; j++) {
//                 result = max(result, abs(maxnum[i] - minnum[j])); 
//             }
//         } 
//         return result; 
//     }
// };



// class Solution {
// public:
//     int maxDistance(vector<vector<int>>& arrays) { 
//         vector<int> minnum; 
//         vector<int> maxnum; 
//         int size = arrays.size(); 
//         for (int i = 0; i < size; i++) {
//             int min_n = arrays[i][0]; 
//             int max_n = arrays[i][arrays[i].size() - 1]; 
//             minnum.push_back(min_n); 
//             maxnum.push_back(max_n);  
//         } 
//         int result = 0; 
//         for (int i = 0; i < size; i++) { 
//             int temp = minnum[i]; 
//             minnum[i] = maxnum[i]; 
//             for (int j = 0; j < size; j++) {
//                 result = max(result, abs(maxnum[i] - minnum[j])); 
//             } 
//             minnum[i] = temp; 
//         } 
//         return result; 
//     }
// };

// class Solution {
// public:
//     int maxDistance(vector<vector<int>>& arrays) { 
//         vector<int> minnum; 
//         vector<int> maxnum; 
//         int size = arrays.size(); 
//         for (int i = 0; i < size; i++) {
//             int min_n = arrays[i][0]; 
//             int max_n = arrays[i][arrays[i].size() - 1]; 
//             minnum.push_back(min_n); 
//             maxnum.push_back(max_n);  
//         } 
//         int result = 0; 
//         for (int i = 0; i < size; i++) {  
//             if (i > 0 && i != size - 1 && maxnum[i] < maxnum[i -1] && minnum[i] > minnum[i - 1]) {
//                 continue; 
//             }
//             int temp = minnum[i]; 
//             minnum[i] = maxnum[i]; 
//             for (int j = 0; j < size; j++) {
//                 result = max(result, abs(maxnum[i] - minnum[j])); 
//             } 
//             minnum[i] = temp; 
//         } 
//         return result; 
//     }
// };



    // class Solution {
// public:
//     int maxDistance(vector<vector<int>>& arrays) { 
//         vector<int> minnum; 
//         vector<int> maxnum; 
//         int size = arrays.size(); 
//         for (int i = 0; i < size; i++) {
//             int min_n = arrays[i][0]; 
//             int max_n = arrays[i][arrays[i].size() - 1]; 
//             minnum.push_back(min_n); 
//             maxnum.push_back(max_n);  
//         } 
//         int result = 0; 
//         for (int i = 0; i < size; i++) {
//             minnum[i] = maxnum[i]; 
//             for (int j = 0; j < size; j++) {
//                 result = max(result, abs(maxnum[i] - minnum[j])); 
//             }
//         } 
//         return result; 
//     }
// };



// class Solution {
// public:
//     int maxDistance(vector<vector<int>>& arrays) { 
//         vector<int> minnum; 
//         vector<int> maxnum; 
//         int size = arrays.size(); 
//         for (int i = 0; i < size; i++) {
//             int min_n = arrays[i][0]; 
//             int max_n = arrays[i][arrays[i].size() - 1]; 
//             minnum.push_back(min_n); 
//             maxnum.push_back(max_n);  
//         } 
//         int result = 0; 
//         for (int i = 0; i < size; i++) { 
//             int temp = minnum[i]; 
//             minnum[i] = maxnum[i]; 
//             for (int j = 0; j < size; j++) {
//                 result = max(result, abs(maxnum[i] - minnum[j])); 
//             } 
//             minnum[i] = temp; 
//         } 
//         return result; 
//     }
// };

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) { 
        int mx = INT_MIN  / 2; 
        int mn = INT_MAX / 2; 
        int ans = 0; 
        for (auto a : arrays) {
            ans = max({ans, a.back() - mn, mx - a[0]}); 
            mn = min(mn, a[0]); 
            mx = max(mx, a.back()); 
        } 
        return ans; 
    }
};



// @lc code=end

