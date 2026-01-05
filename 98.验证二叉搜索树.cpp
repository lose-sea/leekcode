/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
// class Solution {
// public:
// //  中序遍历的结果是有序的 
//     vector<int> vec; 
//     void inorder(TreeNode* root) {
//         if (root == nullptr) {
//             return; 
//         } 
//         inorder(root->left); 
//         vec.push_back(root->val); 
//         inorder(root->right); 
//     }
//     bool isValidBST(TreeNode* root) {
//         if (root == nullptr) {
//             return true; 
//         } 
//         inorder(root); 
//         int len = vec.size(); 
//         for (int i = 1; i < len; i++) {
//             if (vec[i] <= vec[i - 1]) {
//                 return false; 
//             }
//         } 
//         return true; 
//     }
// };

class Solution {
public:

    // 中序遍历 
    bool judge = true; 
    TreeNode* pre = nullptr; 
    void traversal(TreeNode* root) {
        if (judge == false) {
            return; 
        } 
        if (root == nullptr) {
            return; 
        }
        traversal(root->left); 
        if (pre != nullptr && root->val <= pre->val) {
            judge = false; 
            return; 
        } 
        pre = root; 
        traversal(root->right); 
    }
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true; 
        } 
        traversal(root);
        return judge; 
    }
};
// @lc code=end

