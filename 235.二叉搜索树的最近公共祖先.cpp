/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if (root == nullptr || root == p || root == q) {
//             return root; 
//         } 
//         TreeNode* left = lowestCommonAncestor(root->left, p, q); 
//         TreeNode* right = lowestCommonAncestor(root->right, p, q); 
//         if (left != nullptr && right != nullptr) {
//             return root; 
//         }
//         if (left == nullptr && right != nullptr) {
//             return right; 
//         } else if (left != nullptr && right == nullptr) {
//             return left; 
//         } else {
//             return nullptr; 
//         }
//     }
// }; 

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int valP = p->val; 
        int valQ = q->val; 
        int valR = root->val; 
        if (root== nullptr || root == p || root == q) {
            return root; 
        }
        if ((valP < valR && valQ > valR) || (valQ < valR && valP > valR)) {
            return root; 
        } else if (valP < valR && valQ < valR) {
            return lowestCommonAncestor(root->left, p, q); 
        } else {
            return lowestCommonAncestor(root->right, p, q); 
        } 
    }
};
// @lc code=end
