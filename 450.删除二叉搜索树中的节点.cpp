/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
class Solution {
public:
    TreeNode* findMin(TreeNode* root) {
        while (root && root->left) {
            root = root->left; 
        } 
        return root; 
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root; 
        } 
        if (key < root->val) {
            root->left = deleteNode(root->left, key); 
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key); 
        } else { 
            TreeNode* temp; 
            if (root->left == nullptr) {
                temp = root->right; 
                delete(root); 
                return temp; 
            } else if (root->right == nullptr) {
                temp = root->left; 
                delete(root); 
                return temp; 
            } 
            temp = findMin(root->right); 
            root->val = temp->val; 
            root->right = deleteNode(root->right, temp->val); 
        } 
        return root; 
    }
};
// @lc code=end

