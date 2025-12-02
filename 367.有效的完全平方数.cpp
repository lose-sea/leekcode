/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */
#include<iostream> 
#include<climits> 
#include<vector> 
#include<algorithm>
using namespace std; 
// @lc code=start


class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) return true;
        
        long left = 1;  // 使用 long 防止溢出
        long right = num;
        
        while (left <= right) {
            long mid = left + (right - left) / 2;  // 使用除法更安全
            long square = mid * mid;  // 用乘法代替除法
            
            if (square == num) {
                return true;
            } else if (square < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};
// @lc code=end

