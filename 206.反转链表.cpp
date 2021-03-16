/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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

// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };

class Solution {
public:
    ListNode* res;
    ListNode* reverseList(ListNode* head){
        if(!head) return head;
        ListNode* heady = head;
        this->recursive(head);
        heady->next = nullptr;
        return res;
    }

    void recursive(ListNode* head){
        if(head->next == nullptr){
            this->res = head;
            return ;
        }
        ListNode* next = head->next;
        recursive(next);
        next->next = head;
        return ;
    }

    // ListNode* reverseList(ListNode* head){
    //     // iterative solution without extra mem
    //     ListNode* prev = nullptr;
    //     ListNode* next = nullptr;
    //     while(head){
    //         next = head->next;
    //         head->next = prev;
    //         prev = head;
    //         head = next;
    //     }
    //     return prev;
    // }

    // ListNode* reverseList(ListNode* head) {
    //     // iterative solution with extra mem
    //     ListNode* newHead = new ListNode();
    //     while(head){
    //         newHead->val = head->val;
    //         head = head->next;
    //         newHead = new ListNode(0, newHead);
    //     }

    //     return newHead->next;
    // }
};
// @lc code=end

