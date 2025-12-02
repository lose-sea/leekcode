/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head; 
        for (int i = 0; i < k; i++) {
            if (curr = nullptr) {
                return head; 
            } 
            curr = curr->next; 
        } 
        ListNode* dummy = new ListNode(0); 
        dummy->next = reverseKGroup(curr, k); 
        for (int i = 0; i < k; i++) {
            ListNode* temp = head->next; 
            head->next = dummy->next; 
            dummy->next = head; 
            head = temp; 
        } 
        ListNode* result = dummy->next; 
        delete(dummy);
        return result;  
    }
};
// @lc code=end

