/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0); 
        dummyHead->next = head; 
        ListNode* fast = head; 
        ListNode* slow = dummyHead; 
        for (int i = 0; i < n && fast != nullptr; i++) {
            fast = fast->next; 
        } 
        while (fast != nullptr) {
            fast = fast->next; 
            slow = slow->next; 
        } 
        ListNode* temp = slow->next; 
        slow->next = slow->next->next;  
        delete temp; 
        ListNode* ans = dummyHead->next; 
        delete dummyHead; 
        return ans; 
    }
}; 
// @lc code=end

