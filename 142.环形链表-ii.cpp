/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */
#include<iostream> 
#include<set> 
#include<unordered_set>
using namespace std; 
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
//     ListNode *detectCycle(ListNode *head) {
//         ListNode* fast = head; 
//         ListNode* slow = head; 
//         while (fast != nullptr)  { 
//             if (fast->next == NULL) {
//                 return NULL ; 
//             }
//             fast = fast->next->next; 
//             slow = slow->next;  
//             if (fast == slow) {
//                 ListNode* ptr = head; 
//                 while (ptr != slow) {
//                     slow = slow->next; 
//                     ptr = ptr->next; 
//                 } 
//                 return ptr; 
//             } 
//         } 
//         return NULL; 
//     }
// }; 

// 哈希表
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         unordered_set<ListNode*> visited; 
//         while (head != nullptr) {
//             if (visited.count(head)) {
//                 return head; 
//             } 
//             visited.insert(head); 
//             head = head->next; 
//         } 
//         return nullptr; 
//     }
// };  



class Solution {
public:
    ListNode *detectCycle(ListNode *head) { 
        if (head == nullptr || head->next == nullptr) {
            return nullptr; 
        }
        ListNode* fast = head; 
        ListNode* slow = head; 
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next; 
            slow = slow->next;  
            if (fast == slow) {
                fast = head; 
                while (fast != slow) {
                    fast = fast->next; 
                    slow = slow->next; 
                }  
                return slow; 
            } 
        } 
        
        return nullptr;  
    }
};
// @lc code=end

