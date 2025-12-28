/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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

   
   // Definition for a binary tree node.
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
// 前序遍历 
    vector<TreeNode*> preorderTraversal(TreeNode* root, vector<TreeNode*> vec1) {  
        if (root == nullptr) {
            vec1.push_back(root); 
            return vec1; 
        } 
        preorderTraversal(root->left, vec1); 
        preorderTraversal(root->right, vec1); 
    }

    bool isSymmetric(TreeNode* root) {
        vector<TreeNode*> vec1; 
        vector<TreeNode*> vec2; 
        preorderTraversal(root->left, vec1); 
        preorderTraversal(root->right, vec2); 
        int len1 = vec1.size(); 
        int len2 = vec2.size(); 
        if (len1 != len2) {
            return false; 
        } 
        for (int i = 0; i < len1; i++) {
            if (vec1[i] != vec2[i]) {
                return false; 
            }
        } 
        return true; 
    }
};
// @lc code=end

