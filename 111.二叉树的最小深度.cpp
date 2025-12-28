/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
//     int minDepth(TreeNode* root) {
//         if (!root) {
//             return 0; 
//         } 
//         queue<TreeNode*> q; 
//         q.push(root); 
//         int min = 0; 
//         while (!q.empty()) { 
//             min++; 
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
//                 if (!node->left && !node->right) {
//                     return min; 
//                 }
//             } 
//         } 
//         return min; 
//     }
// };

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0; 
        } 
        int m = 0; 
        queue<TreeNode*> que; 
        que.push(root); 
        while (!que.empty()) {
            int len = que.size(); 
            for (int i = 0; i < len; i++) {
                TreeNode* node = que.front(); 
                que.pop(); 
                if (node->left == nullptr && node->right == nullptr) {
                    return m; 
                } 
                if (node->left) {
                    que.push(node->left); 
                } 
                if (node->right) {
                    que.push(node->right); 
                } 
                m++; 
            }
        } 
        return m; 
    }
};
// @lc code=end

