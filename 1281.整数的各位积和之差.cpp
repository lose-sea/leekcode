/*
 * @lc app=leetcode.cn id=1281 lang=cpp
 *
 * [1281] 整数的各位积和之差
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
    int subtractProductAndSum(int n) { 
        int product = 1; 
        int sum = 0; 
        while (n != 0) {
            int c = n % 10; 
            sum += c; 
            product *= c;  
            n /= 10; 
        }
        return product - sum; 
    }
};
// @lc code=end

