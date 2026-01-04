/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* traversal(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr; 
        }
        int max = nums.front(); 
        for (int i = 0; i < nums.size(); i++) {
            if (max < nums[i]) {
                max = nums[i]; 
            }
        } 
        TreeNode* root = new TreeNode(max); 
        auto it = find(nums.begin(), nums.end(), max); 
        int delimiterIndex = it - nums.begin(); 
        vector<int> left(nums.begin(), nums.begin() + delimiterIndex); 
        vector<int> right(nums.begin() + delimiterIndex + 1, nums.end()); 
        root->left = traversal(left); 
        root->right = traversal(right); 
        return root;    
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr; 
        } 
        return traversal(nums); 
    }
};
// @lc code=end

