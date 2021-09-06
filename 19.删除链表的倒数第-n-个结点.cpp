/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */
#include<ds.h>
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
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* header = new ListNode(0, head);
        ListNode *i = header, *j = header;
        n++;
        while(n--) j = j->next;
        while(j){
            j = j->next;
            i = i->next;
        }
        i->next = i->next->next;
        return header->next;
    }


    // ListNode* target;
    // int n;
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     this->n = n;
    //     this->recursive(head);
    //     if(this->target){
    //         this->target->next = this->target->next->next;
    //         return head;
    //     }else{
    //         return head->next;
    //     }
    

    // }

    // int recursive(ListNode* head){
    //     if(head == nullptr) return 0;
    //     int i = recursive(head->next) + 1;
    //     if(i == this->n+1) this->target = head;
    //     return i;
    // }
};
// @lc code=end

