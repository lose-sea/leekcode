/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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

  
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> ret; 
//         if (!root) {
//             return ret; 
//         }  
//         queue<TreeNode*> q; 
//         q.push(root); 
//         while (!q.empty())  {
//             int currentLevelSize = q.size(); 
//             ret.push_back(vector<int> ()); 
//             for (int i = 1; i <= currentLevelSize; i++) {
//                 TreeNode* node = q.front(); 
//                 q.pop(); 
//                 ret.back().push_back(node->val); 
//                 if (node->left) {
//                     q.push(node->left); 
//                 } 
//                 if (node->right) {
//                     q.push(node->right); 
//                 }
//             }
//         } 
//         return ret; 
//     } 
// };


// // // 迭代
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> result; 
//         if (root == nullptr) {
//             return result; 
//         }  
//         queue<TreeNode*> que; 
//         que.emplace(root); 
//         while (!que.empty()) { 
//             vector<int> vec; 
//             int size = que.size();  
//             for (int i = 0; i < size; i++) {
//                 TreeNode* node = que.front(); 
//                 que.pop(); 
//                 vec.emplace_back(node->val); 
//                 if (node->left) {
//                     que.emplace(node->left);  
//                 } 
//                 if (node->right) {
//                     que.emplace(node->right); 
//                 }
//             }
//             result.emplace_back(vec); 
//         }  
//         return result; 
//     } 
// };




 // // 递归法
class Solution {
public: 
    void  order(TreeNode* curr, vector<vector<int>>& result, int depth) {
        if (curr == nullptr) {
            return; 
        } 
        if (result.size() <= depth) {
            result.emplace_back(vector<int>());  
        } 
        result[depth].emplace_back(curr->val); 
        order(curr->left, result, depth + 1); 
        order(curr->right, result, depth + 1);  
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result; 
        int depth = 0; 
        order(root, result, depth); 
        return result; 
    } 
};
// @lc code=end

