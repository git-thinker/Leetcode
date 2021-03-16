/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
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
    void deleteNode(ListNode* node) {
        while(node->next != nullptr){
            node->val = node->next->val;
            if(node->next->next == nullptr){
                ListNode* tmp = node->next;
                node->next = nullptr;
                node = tmp;
            }else{
                node = node->next;
            }
        }
        delete node;
    }
};
// @lc code=end

