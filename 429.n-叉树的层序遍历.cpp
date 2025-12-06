/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
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

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};





// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret; 
        if (!root) {
            return ret; 
        } 
        queue<Node*> q; 
        q.push(root); 
        while (!q.empty()) {
            int currentLevelSize = q.size(); 
            ret.push_back(vector<int> ()); 
            for (int i = 0; i < currentLevelSize; i++) {
                Node* node = q.front(); 
                q.pop(); 
                ret.back().push_back(node->val); 
                int len = node->children.size(); 
                for (int i = 0; i < len; i++) {
                    if (node->children[i]) {
                        q.push(node->children[i]); 
                    }
                }
            }
        } 
        return ret; 
    }
};
// @lc code=end

