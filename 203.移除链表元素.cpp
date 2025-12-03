/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */
#include<iostream> 
using namespace std; 
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */ 
struct ListNode {
    int val; 
    ListNode* next; 
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {} 
    ListNode(int x, ListNode* next) : val(x), next(next) {}
}; 

// 迭代
// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) { 
//         if (head == nullptr) {
//             return nullptr; 
//         }
//         ListNode* dummy = new ListNode(0, head); 
//         ListNode* curr = dummy; 
//     while (curr->next != nullptr) {
//             if (curr->next->val == val) {
//                 ListNode* temp = curr->next; 
//                 curr->next = temp->next; 
//                 delete temp; 
//             } else {
//                 curr = curr->next;
//             }
//         } 
//         ListNode* ans = dummy->next; 
//         delete dummy; 
//         return ans;  
//     }
// };



// 递归
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return head; 
        } 
        head->next = removeElements(head->next, val); 
        return head->val == val ? head->next : head; 
    }
};





























// @lc code=end
