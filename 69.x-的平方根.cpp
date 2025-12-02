/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */
#include<iostream> 
#include<climits> 
#include<vector> 
#include<algorithm>
using namespace std; 
// @lc code=start
// class Solution {
// public:
//     int mySqrt(int x) {
        
//     }
// };



// class Solution {
// public:
//     int mySqrt(int x) {
//         if (x == 0 || x == 1) {
//             return x; 
//         } 
//         int left = 0; 
//         int right = x; 
//         int result = 0; 
//         while (left <= right) {
//             int mid = left + (right - left) / 2; 
//             if (mid <= x / mid) { // 避免mid * mid 溢出，所以用除法比较
//                 result = mid; 
//                 left = mid + 1;  
//             } else { 
//                 right = mid - 1; 
//             }
//         } 
//         return result; 
//     } 
// }; 



class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x; 
        } 
        int left = 0; 
        int right = x; 
        while (left <= right) { 
            int mid = left + ((right - left) >> 1);  
            if (mid < x / mid) {
                left = mid + 1; 
            } else if (mid > x / mid) {
                right = mid - 1;  
            } else {
                return mid; 
            }
        } 
        return right; 
    }  
}; 
// @lc code=end

