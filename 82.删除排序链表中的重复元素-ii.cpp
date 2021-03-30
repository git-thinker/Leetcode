/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ret = new ListNode(-1, head);
        ListNode* prev = ret;
        ListNode* i = head;
        ListNode* j = head;
        while(1){
            if(i == nullptr) break;
            while(j->next && j->next->val == i->val){
                j = j->next;
            }
            if(i != j){
                prev->next = j->next;
                j = prev->next;
                i = prev->next;
            } else if(j == nullptr) break;
            else{
                prev = prev->next;
                i = prev->next;
                j = prev->next;
            }  
        }
        return ret->next;
    }
};
// @lc code=end

