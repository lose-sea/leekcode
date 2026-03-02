/*
 * @lc app=leetcode.cn id=2413 lang=cpp
 *
 * [2413] 最小偶倍数
 */
#include<iostream> 
#include<set> 
#include<unordered_set> 
#include<vector> 
#include<algorithm>  
using namespace std; 
// @lc code=start
class Solution {
public:
    int gcd(int a, int b) {
        a = abs(a); 
        b = abs(b); 
        if (b == 0) {
            return a; 
        } 
        return gcd(b, a % b); 
    }
    int smallestEvenMultiple(int n) {
        return (n / gcd(n, 2)) * 2; 
    }
};
// @lc code=end

