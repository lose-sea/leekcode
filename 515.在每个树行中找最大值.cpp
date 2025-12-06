/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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

   
// // Definition for a binary tree node.
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
    vector<int> largestValues(TreeNode* root) {
        vector<vector<int>> ret; 
        vector<int> result;  
        if (!root) {
            return result; 
        } 
        queue<TreeNode*> q; 
        q.push(root); 
        while (!q.empty()) {
            int currentLevelSize = q.size(); 
            ret.push_back(vector<int> ()); 
            int max = INT_MIN; 
            for (int i = 0; i < currentLevelSize; i++) {
                TreeNode* node = q.front(); 
                q.pop(); 
                max = max > node->val ? max : node->val; 
                ret.back().push_back(node->val); 
                if (node->left) {
                    q.push(node->left); 
                } 
                if (node->right) {
                    q.push(node->right); 
                }  
            }  
            result.push_back(max);
        } 
        return result; 
    }
};
// @lc code=end

