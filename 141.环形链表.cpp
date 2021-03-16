/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *i = head, *j = head;
        while(i){
            if(j->next && j->next->next){
                j = j->next->next;
                i = i->next;
                if(i == j) return true;
            }else{
                return false;
            }
        }
        return false;
    }
};
// @lc code=end

