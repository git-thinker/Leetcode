/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
#include"ds.h"
#include<set>
using namespace std;
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // set<ListNode*> mySet;
        // while(headA){
        //     mySet.insert(headA);
        //     headA = headA->next;
        // }
        // while(headB){
        //     if(mySet.count(headB)) return headB;
        //     headB = headB->next;
        // }
        // return nullptr;

        if(!headA || !headB) return nullptr;
        ListNode *a = headA, *b = headB;
        while(a != b){
            a = a ? a->next : headB;
            b = b ? b->next : headA; 
        }
        return a;
    }
};
// @lc code=end

