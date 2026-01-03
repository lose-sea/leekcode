/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
class Solution {
public: 
    bool result = false; 
    int curr = 0; 
    void traversal(TreeNode* root, int targetSum) {
        if (result == true) {
            return; 
        }  
        curr += root->val; 
        if (root->left == nullptr && root->right == nullptr && curr == targetSum) {
            result = true; 
            return;  
        } 
        if (root->left) {
            traversal(root->left, targetSum); 
        } 
        if (root->right) {
            traversal(root->right, targetSum); 
        }
        curr -= root->val; 
    }
    bool hasPathSum(TreeNode* root, int targetSum) { 
        if (root == nullptr) {
            return false; 
        }
        result = false; 
        traversal(root, targetSum); 
        return result; 
    }
};
// @lc code=end

