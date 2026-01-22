/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
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
    bool lemonadeChange(vector<int>& bills) { 
        int len = bills.size();  
        if (len == 1) {
            if (bills[0] == 5) {
                return true; 
            } else {
                return false; 
            }
        } 
        int five = 0; 
        int ten = 0; 
        int twenty = 0; 
        for (int i = 0; i < len; i++) {
            if (bills[i] == 5) {
                five++; 
            } else if (bills[i] == 10) { 
                ten++; 
                if (five != 0) {
                    five--; 
                } else {
                    return false; 
                }
            } else { 
                twenty++; 
                if (ten > 0 && five > 0) {
                    ten--; 
                    five--; 
                } else if (five >= 3){
                    five -= 3; 
                } else {
                    return false; 
                }
            }
        } 
        return true; 
    }
};
// @lc code=end

