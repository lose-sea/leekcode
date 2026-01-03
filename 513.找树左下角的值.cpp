/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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


 // 采用层序遍历
// class Solution {
// public:
//     int findBottomLeftValue(TreeNode* root) {  
//         int result = 0; 
//         if (root == nullptr) {
//             return result; 
//         } 
//         queue<TreeNode*> curr; 
//         curr.push(root); 
//         while (!curr.empty()) { 
//             int len = curr.size(); 
//             TreeNode* node = curr.front();  
//             result = node->val; 
//             for (int i = 0; i < len; i++) { 
//                 node = curr.front();     
//                 curr.pop(); 
//                 if (node->left) {
//                     curr.push(node->left); 
//                 } 
//                 if (node->right) {
//                     curr.push(node->right); 
//                 }
//             }
//         } 
//         return result; 
//    }
// };



// 采用递归
class Solution {
public:
    int depth = 0; 
    int result = 0; 
    void path(TreeNode* root, int curr) {
        if (root == nullptr) {
            return; 
        }   
        if (curr > depth) { 
            depth = curr; 
            result = root->val; 
        } 
        path(root->left, curr + 1); 
        path(root->right, curr + 1); 
    }
    int findBottomLeftValue(TreeNode* root) {  
        if (root == nullptr) {
            return 0; 
        }
        path(root, 1); 
        return result; 
   }
};
// @lc code=end

