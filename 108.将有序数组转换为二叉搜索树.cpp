/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
//     TreeNode* buildTree(vector<int>& nums) {
//         if (nums.empty()) {
//             return nullptr; 
//         } 
//         int len = nums.size(); 
//         int mid = len / 2; 
//         TreeNode* root = new TreeNode(nums[mid]); 
//         vector<int> left(nums.begin(), nums.begin() + mid); 
//         vector<int> right(nums.begin() + mid + 1, nums.end()); 
//         root->left = buildTree(left); 
//         root->right = buildTree(right); 
//         return root;  
//     }
    
//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         if (nums.empty()) {
//             return nullptr; 
//         } 
//         TreeNode* root = buildTree(nums); 
//         return root; 
//     }
// };

class Solution {
public: 
    TreeNode* buildTree(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return nullptr; 
        } 
        int mid = left + (right - left) / 2; 
        TreeNode* root = new TreeNode(nums[mid]); 
        root->left = buildTree(nums, left, mid); 
        root->right = buildTree(nums, mid + 1, right); 
        return root; 
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr; 
        } 
        return buildTree(nums, 0, nums.size()); 
    }
};
// @lc code=end

