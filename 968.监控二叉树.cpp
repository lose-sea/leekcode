/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
using namespace std; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public: 
    int result = 0; 
    int traversal(TreeNode* curr) {
        if (curr == nullptr) {
            return 2; 
        } 
        int left = traversal(curr->left); 
        int right = traversal(curr->right); 

        if (left == 2 && right == 2) {
            return 0; 
        } 
        if (left == 0 || right == 0) {
            result++;  
            return 1; 
        } 
        if (left == 1 || right == 1) {
            return 2; 
        } 
        return -1; 
    }

    int minCameraCover(TreeNode* root) {
        if (root == nullptr) {
            return 0; 
        } 
        result = 0; 
        if (traversal(root) == 0) {
            result++; 
        } 
        return result; 
    }
};
// @lc code=end

