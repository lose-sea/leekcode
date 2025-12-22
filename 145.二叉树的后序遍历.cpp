/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
   
   // // Definition for a binary tree node.
   struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode() : val(0), left(nullptr), right(nullptr) {}
       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
   };
 
//  // 递归
// class Solution { 
//     vector<int> result; 
// public:
//     vector<int> postorderTraversal(TreeNode* root) { 
//         if (root == nullptr) {
//             return result; 
//         }
//         postorderTraversal(root->left); 
//         postorderTraversal(root->right); 
//         result.emplace_back(root->val); 
//         return result; 
//     } 
// };



// // 迭代
// class Solution { 
// public:
//     vector<int> postorderTraversal(TreeNode* root) { 
//         vector<int> result; 

//         if (root == nullptr) {
//             return result; 
//         } 
//         stack<TreeNode*> stk; 
//         TreeNode* prev = nullptr; 
//         TreeNode* node = root; 
//         while (!stk.empty() || node != nullptr) {
//             while (node != nullptr) {
//                 stk.emplace(node); 
//                 node = node->left; 
//             } 
//             node = stk.top(); 
//             stk.pop(); 
//             if (node->right == nullptr || node->right == prev) {
//                 result.emplace_back(node->val); 
//                 prev = node; 
//                 node = nullptr; 
//             } else {
//                 stk.emplace(node); 
//                 node = node->right; 
//             }
//         } 
//         return result; 
//     } 
// }; 

// 迭代
class Solution { 
public:
    vector<int> postorderTraversal(TreeNode* root) { 
        vector<int> result; 
        if (root == nullptr) {
            return result; 
        } 
        stack<TreeNode*> stk; 
        TreeNode* prev = nullptr;  
        while (!stk.empty() || root != nullptr) {
            while (root != nullptr) {
                stk.emplace(root); 
                root = root->left; 
            } 
            root = stk.top(); 
            stk.pop(); 
            if (root->right == nullptr || root->right == prev) {
                result.emplace_back(root->val); 
                stk.pop(); 
                prev = root; 
                root = nullptr; 
            } else { 
                stk.emplace(root); 
                root = root->right; 
            }
        } 
        return result; 
    } 
};
// @lc code=end

