/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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

//  // 递归
// class Solution {
// public:
//     vector<int> result;  
//     vector<int> inorderTraversal(TreeNode* root) { 
//         if (root == nullptr) {
//             return result; 
//         } 
//         inorderTraversal(root->left); 
//         result.emplace_back(root->val); 
//         inorderTraversal(root->right);  
//         return result; 
//     }
// }; 




 // 迭代
class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;  
        if (root == nullptr) {
            return result; 
        } 
        stack<TreeNode*> stk; 
        TreeNode* node = root; 
        while (!stk.empty() || node != nullptr) { 
            while (node != nullptr) {
                stk.emplace(node); 
                node = node->left; 
            } 
            node = stk.top(); 
            stk.pop(); 
            result.emplace_back(node->val); 
            node = node->right;  
        } 
        return result; 
    }
};
// @lc code=end

