/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
#include"ds.h"
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* cursor = head;
        ListNode* tail;
        int num = 0;
        while(cursor){
            num++;
            if(cursor->next) tail = cursor->next;
            cursor = cursor->next;
        }
        cursor = head;
        if(num <= 2) return head;
        for(int i = 0; i < num / 2; ++i){
            ListNode* fraction = getOff(cursor);
            tail = append(fraction, tail);
            cursor = cursor->next;
        }
        return head;

    }

    ListNode* getOff(ListNode* prev){
        ListNode* ret = prev->next;
        prev->next = ret->next;
        ret->next = nullptr;
        return ret;
    }

    ListNode* append(ListNode* fraction, ListNode* tail){
        tail->next = fraction;
        return fraction;
    }
    
};
// @lc code=end

