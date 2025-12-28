/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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

  
// // Definition for a binary tree node.
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
//     vector<int> rightSideView(TreeNode* root) {
//         vector<vector<int>> ret; 
//         vector<int> result; 
//         if (!root) {
//             return result;  
//         } 
//         queue<TreeNode*> q; 
//         q.push(root);  
//         int num = root->val; 
//         while (!q.empty()) {
//             int currentLevelSize = q.size(); 
//             ret.push_back(vector<int> ()); 
//             for (int i  = 0; i < currentLevelSize; i++) {
//                 TreeNode* node = q.front(); 
//                 q.pop(); 
//                 num = node->val; 
//                 ret.back().push_back(node->val); 
//                 if (node->left) {
//                     q.push(node->left); 
//                 } 
//                 if (node->right) {
//                     q.push(node->right); 
//                 }
//             } 
//             result.push_back(num); 
//         } 
//         return result; 
//     }
// };  



class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> ret; 
        vector<int> result; 
        if (!root) {
            return result;  
        } 
        queue<TreeNode*> que; 
        que.emplace(root); 
        while (!que.empty()) {
            int len = que.size(); 
            for (int i = 0; i < len; i++) { 
                TreeNode* node = que.front(); 
                que.pop(); 
                if (i == len - 1) {
                    result.emplace_back(node->val); 
                } 
                if (node->left) {
                    que.push(node->left); 
                } 
                if (node->right) {
                    que.push(node->right); 
                }
            } 
        } 
        return result; 
    }
}; 
// @lc code=end

