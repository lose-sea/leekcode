/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
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


// 方法一
// class Solution {
// public: 
//     int addDigits(int num) {
//         int result = 0;  
//         if (num < 10) {
//             return num; 
//         }
//         while (num != 0) {
//             int c = num % 10; 
//             result += c; 
//             num /= 10; 
//         } 
//         return addDigits(result); 
//     }
// }; 


// 方法二
class Solution {
public: 
    int addDigits(int num) {
        while (num >= 10) {
            int sum = 0;  
            while (num != 0) {
                sum += num % 10; 
                num /= 10; 
            } 
            num = sum; 
        } 
        return num; 
    }
};
// @lc code=end

