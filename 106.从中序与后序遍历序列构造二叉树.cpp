/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty()) {
            return nullptr; 
        } 
        // 找到后序遍历的最后一个节点, 就是当前的中间节点
        int rootValue = postorder.back();  
        postorder.pop_back();  
        TreeNode* root = new TreeNode(rootValue); 
        if (inorder.size() == 1) {
            return root; 
        } 
        // 找到中序遍历的切割点
        int delimiterIndex; 
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
            if (inorder.at(delimiterIndex) == rootValue) {
                break; 
            }
        } 
        
        // 切割中序数组
        // 左闭右开区间 
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex); 
        vector<int> rightInorder(inorder.begin() + leftInorder.size() + 1, inorder.end()); 

        // 切割后序数组
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size()); 
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end()); 

        root->left = traversal(leftInorder, leftPostorder); 
        root->right = traversal(rightInorder, rightPostorder); 
        
        return root; 
    } 

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty()) {
            return nullptr; 
        } 
        return traversal(inorder, postorder); 
    }
};
// @lc code=end

