/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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

    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr; 
        } 
        int rootValue = preorder.front(); 
        preorder.erase(preorder.begin()); 
        TreeNode* root = new TreeNode(rootValue); 
        if (inorder.size() == 1) {
            return root; 
        } 
        auto it = find(inorder.begin(), inorder.end(), rootValue); 
        int delimiterIndex = it - inorder.begin(); 

        // 分割中序数组
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex); 
        vector<int> rightIndex(inorder.begin() + delimiterIndex + 1, inorder.end()); 

        // 分隔前序数组
        vector<int> leftPreorder(preorder.begin(), preorder.begin() + delimiterIndex); 
        vector<int> rightPreorder(preorder.begin() + delimiterIndex, preorder.end()); 
        
        root->left = traversal(leftPreorder, leftInorder); 
        root->right = traversal(rightPreorder, rightIndex); 

        return root; 
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.empty()) {
            return nullptr; 
        } 
        return traversal(preorder, inorder); 
    }
};
// @lc code=end

