/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
using namespace std;  

   
   // Definition for a binary tree node.
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
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if (!root) {
//             return 0; 
//         } 
//         queue<TreeNode*> q; 
//         q.push(root); 
//         int max = 0; 
//         while (!q.empty()) {
//             int currentLevelSize = q.size(); 
//             for (int i = 0; i < currentLevelSize; i++) {
//                 TreeNode* node = q.front(); 
//                 q.pop();  
//                 if (node->left) {
//                     q.push(node->left); 
//                 } 
//                 if (node->right) {
//                     q.push(node->right); 
//                 } 
//             } 
//             max++; 
//         } 
//         return max; 
//     }
// };


// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if (!root) {
//             return 0; 
//         } 
//         int m = 0; 
//         queue<TreeNode*> que; 
//         que.push(root); 
//         while (!que.empty()) { 
//             m++; 
//             int len = que.size(); 
//             for (int i = 0; i < len; i++) {
//                 TreeNode* node = que.front(); 
//                 que.pop(); 
//                 if (node->left) {
//                     que.push(node->left); 
//                 } 
//                 if (node->right) {
//                     que.push(node->right); 
//                 }
//             }
//         } 
//         return m; 
//     }
// };


class Solution {
public:
    int result; 
    void getDepth(TreeNode* root, int depth) { 
        result = result > depth ? result : depth; 
        if (root == nullptr) {
            return; 
        } 
        if (root->left) {
            depth++; 
            getDepth(root->left, depth); 
            depth--; 
        } 
        if (root->right) {
            depth++; 
            getDepth(root->right, depth); 
            depth--; 
        } 
    }
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return result; 
        } 
        getDepth(root, 1); 
        return result; 
    }
};
// @lc code=end

