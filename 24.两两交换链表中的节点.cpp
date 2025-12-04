/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */
#include<iostream> 
#include<vector> 
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
public : 
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         ListNode* dummyHead = new ListNode(0); 
//         dummyHead->next = head; 
//         ListNode* temp = dummyHead; 
//         while (temp->next != nullptr && temp->next->next != nullptr) {
//             ListNode* node1 = temp->next; 
//             ListNode* node2 = node1->next; 
//             temp->next = node2; 
//             node1->next = node2->next; 
//             node2->next = node1; 
//             temp = node1; 
//         } 
//         ListNode* ans = dummyHead->next; 
//         delete dummyHead; 
//         return ans; 
//     }
// }; 


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0, head); 
        ListNode* prev = dummyHead; 
        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* curr = prev->next; 
            ListNode* next = curr->next; 
            curr->next = next->next; 
            next->next = curr; 
            prev->next = next;  
            prev = curr; 
        } 
        ListNode* result = dummyHead->next; 
        delete(dummyHead); 
        return result; 
    }
}; 
// @lc code=end

