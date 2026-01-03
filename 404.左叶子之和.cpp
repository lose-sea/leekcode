/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) { 
            return 0; 
        } 
        int sum = 0; 
        stack<TreeNode*> stk; 
        //  前序遍历 
        stk.push(root); 
        while (!stk.empty()) {
            TreeNode* node = stk.top(); 
            if (node != nullptr) {
                stk.pop(); 
                if (node->right) {
                    stk.push(node->right);
                } 
                stk.push(node); 
                stk.push(nullptr); 
                if (node->left) {
                    stk.push(node->left);  
                    TreeNode* temp = node->left; 
                    if (temp->left == nullptr && temp->right == nullptr) {
                        sum += temp->val; 
                    }
                } 
            } else {
                stk.pop(); 
                stk.pop(); 
            } 
        }  
        return sum; 
    }
};
// @lc code=end

