/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
#include "ds.h"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* fake = new ListNode(-1, head);
        head = fake;
        for(int i = 1; i < left; i++, head = head->next);
        head->next = this->reverse(head->next, right - left + 1);
        return fake->next;
    }

    ListNode* reverse(ListNode* head, int n){
        if(!n) return head;
        ListNode* cursor = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while(n--){
            next = cursor->next;
            cursor->next = prev;
            prev = cursor;
            cursor = next;
        }
        head->next = next;
        return prev;
    }
};

// @lc code=end

