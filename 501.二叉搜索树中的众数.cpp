/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    void searchBST(TreeNode* root, unordered_map<int, int>& map) {
        if (root == nullptr) {
            return; 
        }
        map[root->val]++; 
        searchBST(root->left, map); 
        searchBST(root->right, map); 
    } 
    bool static cmp(const pair<int, int>& e1, const pair<int, int>& e2) {
        return e1.second > e2.second; 
    }
    vector<int> findMode(TreeNode* root) { 
        vector<int> result; 
        unordered_map<int, int> map; 
        if (root == nullptr) {
            return result; 
        }
        searchBST(root, map); 
        vector<pair<int, int>> vec(map.begin(), map.end()); 
        sort(vec.begin(), vec.end(), cmp); 
        int len = vec.front().second; 
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i].second == len) {
                result.push_back(vec[i].first); 
            } else {
                break; 
            }
        } 
        return result; 
    }
};
// @lc code=end

