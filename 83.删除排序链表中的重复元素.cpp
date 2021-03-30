/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cursor = head;
        if(!head) return head;
        while(cursor->next){
            if(cursor->val == cursor->next->val){
                ListNode* tmp = cursor->next;
                cursor->next = tmp->next;
                delete tmp;
            }else{
                cursor = cursor->next;
            }
        }
        return head;
    }
};
// @lc code=end

