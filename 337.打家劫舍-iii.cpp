/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
// 暴力递归  (超时)
// class Solution {
// public: 
//     int rob(TreeNode* root) {
//         if (root == nullptr) {
//             return 0; 
//         } 
//         if (root->left == 0 && root->right == nullptr) {
//             return root->val; 
//         }  
//         // 偷当前节点 
//         int val1 = root->val; 
//         if (root->left) {
//             val1 += rob(root->left->left) + rob(root->left->right); 
//         }
//         if (root->right) {
//             val1 += rob(root->right->left) + rob(root->right->right); 
//         } 
//         // 偷父节点
//         int val2 = rob(root->left) + rob(root->right); 
//         return max(val1, val2); 
//     }
// };


// // 记忆化递归
// class Solution {
// public: 
//     unordered_map<TreeNode*, int> umap; 
//     int rob(TreeNode* root) {
//         if (root == nullptr) {
//             return 0; 
//         } 
//         if (root->left == 0 && root->right == nullptr) {
//             return root->val; 
//         }    
//         if (umap[root]) {
//             return umap[root]; 
//         }
//         // 偷父节点 
//         int val1 = root->val; 
//         if (root->left) {
//             val1 += rob(root->left->left) + rob(root->left->right); 
//         }
//         if (root->right) {
//             val1 += rob(root->right->left) + rob(root->right->right); 
//         } 
//         // 不偷父节点
//         int val2 = rob(root->left) + rob(root->right);  
//         umap[root] = max(val1, val2); 
//         return max(val1, val2); 
//     }
// };   


// 动态规划(后序遍历)
class Solution {
public: 
    vector<int> robTree(TreeNode* cur) {
        if (cur == nullptr) {
            return {0, 0}; 
        } 
        vector<int> left = robTree(cur->left); 
        vector<int> right = robTree(cur->right); 

        // 偷cur, 那么就不能偷左右节点 
        int val1 = cur->val + left[0] + right[0];  
        
        // 不偷cur, 那么就可以偷野可以不偷左右节点, 则取较大值的情况 
        int val2 = max(left[0], left[1]) + max(right[0], right[1]); 
        return {val2, val1}; 
    } 
    int rob(TreeNode* root) {
        vector<int> result = robTree(root); 
        return max(result[0], result[1]); 
    }
};   
// @lc code=end

