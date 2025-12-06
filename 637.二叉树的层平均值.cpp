/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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

  
// // Definition for a binary tree node.
struct TreeNode { 
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};






class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> ret; 
        vector<double> result; 
        if (!root) {
            return result; 
        }  
        queue<TreeNode*> q; 
        q.push(root); 
        while (!q.empty()) { 
            int currentLevelSize = q.size(); 
            ret.push_back(vector<int> ()); 
            double sum = 0; 
            for (int i = 0; i < currentLevelSize; i++) { 
                TreeNode* node = q.front(); 
                sum += node->val; 
                q.pop(); 
                ret.back().push_back(node->val); 
                if (node->left) {
                    q.push(node->left); 
                } 
                if (node->right) {
                    q.push(node->right); 
                } 
            } 
            result.push_back(sum / (double)currentLevelSize); 
        } 
        return result; 
    }
};





// @lc code=end

