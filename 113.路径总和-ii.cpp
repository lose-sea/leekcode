/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
// class Solution {
// public: 
//     vector<vector<int>> result; 
//     vector<int> curr; 
//     int sum = 0; 
//     void traversal(TreeNode* root, int targetSum) { 
//         curr.push_back(root->val);  
//         sum += root->val; 
//         if (root->left == nullptr && root->right == nullptr) {
//             if (sum == targetSum) {
//                 result.push_back(curr); 
//             }  
//             curr.pop_back();  
//             sum -= root->val; 
//             return; 
//         } 
//         if (root->left) { 
//             traversal(root->left, targetSum); 
//         } 
//         if (root->right) { 
//             traversal(root->right, targetSum); 
//         } 
//         curr.pop_back();  
//         sum -= root->val; 
//     }
//     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//         if (root == nullptr) {
//             return result; 
//         } 
//         traversal(root, targetSum); 
//         return result; 
//     }
// };



class Solution {
public: 
    vector<vector<int>> result; 
    vector<int> curr; 
    int sum = 0; 
    void traversal(TreeNode* root, int targetSum) { 
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == targetSum) {
                result.push_back(curr); 
            }  
            return; 
        } 
        if (root->left) { 
            curr.push_back(root->left->val); 
            sum += root->left->val; 
            traversal(root->left, targetSum); 
            curr.pop_back(); 
            sum -= root->left->val; 
        } 
        if (root->right) { 
            curr.push_back(root->right->val); 
            sum += root->right->val; 
            traversal(root->right, targetSum); 
            curr.pop_back(); 
            sum -= root->right->val; 
        } 
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return result; 
        } 
        sum = root->val; 
        curr.push_back(root->val); 
        traversal(root, targetSum); 
        return result; 
    }
};
// @lc code=end

