/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3 的幂
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
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;  
        } 
        if (n == 1) {
            return true; 
        }   
        while (n % 3 == 0) {
            n /= 3; 
        } 
        return n == 1; 
    }
};
// @lc code=end

