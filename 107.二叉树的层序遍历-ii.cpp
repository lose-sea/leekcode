/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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



// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret; 
        if (!root) {
            return ret; 
        }  
        queue<TreeNode*> q; 
        q.push(root); 
        while (!q.empty())  {
            int currentLevelSize = q.size(); 
            ret.push_back(vector<int> ()); 
            for (int i = 1; i <= currentLevelSize; i++) {
                TreeNode* node = q.front(); 
                q.pop(); 
                ret.back().push_back(node->val); 
                if (node->left) {
                    q.push(node->left); 
                } 
                if (node->right) {
                    q.push(node->right); 
                }
            } 
        } 
        reverse(ret.begin(), ret.end()); 
        return ret; 
    }
};
// @lc code=end

