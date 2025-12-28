/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
// 广度优先搜索
// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if (!root) {
//             return root; 
//         }  
//         queue<TreeNode*> q; 
//         q.push(root); 
//         while (!q.empty())  {
//             int currentLevelSize = q.size(); 
//             for (int i = 1; i <= currentLevelSize; i++) {
//                 TreeNode* node = q.front(); 
//                 q.pop(); 
//                 TreeNode* temp = node->left; 
//                 node->left = node->right; 
//                 node->right = temp; 
//                 if (node->left) {
//                     q.push(node->left); 
//                 } 
//                 if (node->right) {
//                     q.push(node->right); 
//                 }
//             }
//         } 
//         return root; 
//     }
// };




// // 递归
// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if (!root) {
//             return root; 
//         }  
//         swap(root->left, root->right); 
//         invertTree(root->left); 
//         invertTree(root->right); 
//         return root; 
//     }
// };

// // 递归
// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if (root == nullptr) {
//             return root; 
//         }  
//         swap(root->left, root->right); 
//         invertTree(root->left); 
//         invertTree(root->right); 
//         return root; 
//     }
// };



class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root; 
        }  
        queue<TreeNode*> que; 
        que.push(root); 
        while (!que.empty()) {
            int len = que.size(); 
            for (int i = 0; i < len; i++) {
                TreeNode* node = que.front(); 
                que.pop(); 
                if (node->left) {
                    que.push(node->left); 
                } 
                if (node->right) {
                    que.push(node->right); 
                } 
                TreeNode* temp = node->left; 
                node->left = node->right;  
                node->right = temp; 
            }
        } 
        return root; 
    }
};
// @lc code=end

