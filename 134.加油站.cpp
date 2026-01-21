/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
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
// // 暴力(会超时)
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         for (int i = 0; i < gas.size(); i++) {
//             int rest = gas[i] - cost[i]; 
//             int index = (i + 1) % gas.size();  
//             while (rest > 0 && index != i) {
//                 rest += gas[index] - cost[index]; 
//                 index = (index + 1) % gas.size(); 
//             } 
//             if (rest >= 0 && index == i) {
//                 return i; 
//             }
//         }
//         return -1; 
//     }
// };  

// 贪心
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//        int curr = 0; 
//        int min = INT_MAX; 
//        for (int i = 0; i < gas.size(); i++) {
//           curr += (gas[i] - cost[i]); 
//           if (curr < min) {
//                min = curr; 
//           }
//        } 
//        if (curr < 0) {
//             return -1; 
//        } 
//        if (min >= 0) {
//           return 0; 
//        } 
//        for (int i = gas.size() - 1; i >= 0; i--) {
//           min += (gas[i] - cost[i]); 
//           if (min >= 0) {
//                return i; 
//           }
//        } 
//        return -1; 
//     }
// };  

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
          int currsum = 0; 
          int totalsum = 0; 
          int start = 0; 
          for (int i = 0; i < gas.size(); i++) {
               currsum += gas[i] - cost[i]; 
               totalsum += gas[i] - cost[i];  
               if (currsum < 0) {
                    start = i + 1; 
                    currsum = 0; 
               } 
          }  
          if (totalsum < 0) {
               return -1; 
          } 
          return start; 
    }
}; 
// @lc code=end

