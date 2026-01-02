/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */
#include<iostream> 
#include<set> 
#include<unordered_set> 
#include<unordered_map>
#include<vector> 
#include<algorithm>   
#include<queue>  
#include<string> 
#include<cmath>
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
    vector<string> result; 
    vector<int> curr; 
    void path(TreeNode* root) {  
        curr.push_back(root->val); 
        if (root->left == nullptr && root->right == nullptr) { 
            string res; 
            for (int i = 0; i < curr.size() - 1; i++) {
                res += to_string(curr[i]); 
                res += "->"; 
            } 
            res += to_string(curr.back()); 
            result.push_back(res); 
            return; 
        }  
        if (root->left) {
            path(root->left); 
            curr.pop_back(); 
        } 
        if (root->right) { 
            path(root->right); 
            curr.pop_back(); 
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) { 
        if (root == nullptr) {
            return result; 
        }
        path(root); 
        return result; 
    }
};
// @lc code=end

