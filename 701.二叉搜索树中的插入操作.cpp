/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
// // 递归
// class Solution {
// public:
//     TreeNode* insertIntoBST(TreeNode* root, int val) {
//         TreeNode* node = new TreeNode(val); 
//         if (root == nullptr) {
//             return node; 
//         } 
//         if (val < root->val) {
//             root->left = insertIntoBST(root->left ,val); 
//         } else {
//             root->right =  insertIntoBST(root->right, val);
//         }  
//         return root; 
//     } 
// }; 

// 迭代
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val); 
        if (root == nullptr) {
            return node; 
        } 
        TreeNode* curr = root; 
        TreeNode* pre = root; 
        while (curr) {
            pre = curr; 
            if (val < curr->val) {
                curr = curr->left;  
            } else {
                curr = curr->right; 
            }
        } 
        if (val < pre->val) {
            pre->left = node; 
        } else {
            pre->right = node; 
        } 
        return root; 
    } 
};
// @lc code=end

