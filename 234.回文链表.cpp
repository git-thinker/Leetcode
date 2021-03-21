/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
// #include<vector>
// using namespace std;
// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) return false;
        ListNode *i = head, *j = head;
        while(j->next){
            j = j->next;
            if(j->next){
                j = j->next;
                i = i->next;
            }else{
                break;
            }
        }
        i->next = this->reverse(i->next);
        i = i->next;
        j = head;
        while(i != nullptr){
            if(i->val != j->val) return false;
            i = i->next;
            j = j->next;
        }
        return true;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    // bool isPalindrome(ListNode* head) {
    //     vector<int> vec;
    //     for(; head != nullptr; head = head->next) vec.emplace_back(head->val);
    //     for(int i = 0, j = vec.size()-1; i < j;i++, j--) if(vec[i] != vec[j]) return false;
    //     return true;
    // }
};
// @lc code=end

