/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
// #include"ds.h"
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;
        ListNode* cursor;
        ListNode* lastValid;
        int n = 1;
        int i = 0;
        cursor = head;
        while(cursor->next){
            n++;
            cursor = cursor->next;
        } 
        k %= n;
        lastValid = cursor;
        for(cursor = head, i = 0; i != n - k - 1; i++, cursor = cursor->next);
        lastValid->next = head;
        head = cursor->next;
        cursor->next = nullptr;
        return head;
    }
};
// @lc code=end

