/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
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

// // 方法一
// class Solution {
// public:
//     bool isPowerOfTwo(int n) {   
//         if (n == 0) {
//             return false; 
//         }
//         if (n == 1) {
//             return true; 
//         }
//         if (n % 2 == 1 || n < 0) {
//             return false; 
//         }
//         while (n % 2 == 0) { 
//             n /= 2; 
//         }     
//         return n == 1; 
//     }
// };



// // 方法二(位运算)
// class Solution {
// public:
//     bool isPowerOfTwo(int n) {   
//         return n > 0 && (n & (n - 1)) == 0; 
//     }
// }; 


// 方法三
class Solution {
public:
    bool isPowerOfTwo(int n) {   
        return n > 0 && (n & -n) == n; 
    }
}; 
// @lc code=end

