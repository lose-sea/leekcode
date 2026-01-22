/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
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
    int monotoneIncreasingDigits(int n) {
        string num = to_string(n); 
        int flag = num.size();   
        for (int i = num.size() - 1; i >= 1; i--) {
            if (num[i - 1] > num[i]) {
                flag = i; 
                num[i - 1]--; 
            }
        } 
        for (int i = flag; i < num.size(); i++) {
            num[i] = '9'; 
        }
        return stoi(num); 
    }
};
// @lc code=end

