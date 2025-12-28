/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
/*
 * Definition for a binary tree node.*/
   struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode() : val(0), left(nullptr), right(nullptr) {}
       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
   };
   
// // 递归
// class Solution {
// public:
//     vector<int> result; 
//     vector<int> preorderTraversal(TreeNode* root) { 

//         if (root == nullptr) {
//             return result; 
//         }
//         result.push_back(root->val); 
//         preorderTraversal(root->left); 
//         preorderTraversal(root->right); 
//         return result; 
//     }
// };


// // 迭代
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) { 
//         vector<int> result; 
//         stack<TreeNode*> stk; 
//         if (root == NULL) {
//             return result; 
//         } 
//         TreeNode* node = root;   
//         while (!stk.empty() || node != nullptr) {
//             while (node != nullptr) {
//                 stk.emplace(node); 
//                 result.emplace_back(node->val); 
//                 node = node->left; 
//             } 
//             node = stk.top(); 
//             stk.pop(); 
//             node = node->right; 
//         }
//         return result; 
//     }
// };


// // 迭代
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) { 
//         vector<int> result;  
//         if (root == nullptr) {
//             return result; 
//         }
//         stack<TreeNode*> stk; 
//         stk.push(root); 
//         while (!stk.empty()) {
//             TreeNode* node = stk.top(); 
//             stk.pop(); 
//             result.emplace_back(node->val); 
//             if (node->right) {
//                 stk.emplace(node->right); 
//             } 
//             if (node->left) {
//                 stk.emplace(node->left); 
//             } 
//         } 
//         return result; 
//     }
// };




// // 迭代
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) { 
//         vector<int> result; 
//         if (root == nullptr) {
//             return result; 
//         };  
//         stack<TreeNode*> stk; 
//         TreeNode* node = root; 
//         while (!stk.empty() || node != nullptr) {
//             while (node != nullptr) { 
//                 result.emplace_back(node->val); 
//                 stk.emplace(node);
//                 node = node->left; 
//             } 
//             node = stk.top(); 
//             stk.pop(); 
//             node = node->right; 
//         } 
//         return result; 
//     }
// };



// // 迭代
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) { 
//         vector<int> result; 
//         if (root == nullptr) {
//           return result; 
//         } 
//         stack<TreeNode*> stk; 
//         TreeNode* node = root; 
//         while (!stk.empty() || node != nullptr) {
//             while (node) {
//                 stk.emplace(node); 
//                 result.emplace_back(node->val); 
//                 node = node->left; 
//             } 
//             node = stk.top(); 
//             stk.pop(); 
//             node = node->right; 
//         } 
//         return result; 
//     }
// };



// // 迭代
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) { 
//         vector<int> result; 
//         if (root == nullptr) {
//             return result; 
//         } 
//         stack<TreeNode*> stk; 
//         stk.emplace(root); 
//         while (!stk.empty()) {
//             TreeNode* node = stk.top(); 
//             if (node) { 
//                 stk.pop(); 
//                 if (node->right) {
//                     stk.emplace(node->right); 
//                 }  
//                 if (node->left) {
//                     stk.emplace(node->left); 
//                 } 
//                 stk.emplace(node); 
//                 stk.emplace(nullptr); 
//             } else {
//                 stk.pop(); 
//                 node = stk.top(); 
//                 stk.pop(); 
//                 result.emplace_back(node->val); 
//             }
//         } 
//         return result; 
//     }
// };


// // 迭代
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) { 
//         vector<int> result; 
//         if (root == nullptr) {
//             return result; 
//         } 
//         stack<TreeNode*> stk; 
//         stk.push(root); 
//         while (!stk.empty()) {
//             TreeNode* node = stk.top(); 
//             stk.pop(); 
//             result.emplace_back(node->val); 
//             if (node->right) {
//                 stk.push(node->right); 
//             } 
//             if (node->left) {
//               stk.push(node->left); 
//             }
//         } 
//         return result; 
//     }
// };

// // 迭代
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) { 
        vector<int> result; 
        if (root == nullptr) {
            return result; 
        } 
        stack<TreeNode*> stk; 
        TreeNode* node = root;  
        stk.push(root); 
        while (!stk.empty()) {
            TreeNode* node = stk.top(); 
            stk.pop(); 
            result.push_back(node->val); 
            if (node->right) {
                stk.push(node->right); 
            } 
            if (node->left) {
                stk.push(node->left); 
            }
        }
        return result; 
    } 
}; 







// @lc code=end

