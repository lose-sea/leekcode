/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */
#include<iostream> 
#include<set> 
#include<unordered_set> 
#include<vector> 
#include<string> 
#include<algorithm>  
using namespace std;
// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size(); 
        int len2 = needle.size();  
        for (int i = 0; i <= len1 - len2; i++) { 
            int size = 0; 
            for (int j = 0; j < len2; j++) { 
                if (haystack[i + j] != needle[j]) {
                    break; 
                }   
                size++; 
            } 
            if (size == len2) {
                return i ;
            }
        } 
        return -1; 
    }
};
// @lc code=end

