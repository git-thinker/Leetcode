/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */
#include<ds.h>
#include<queue>
#include<vector>
#include<map>
using namespace std;
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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> q;
        ListNode* root = new ListNode();
        ListNode* cursor = root;
        map<int, queue<int>> header_map;
        int not_empty_link = lists.size();
        int number;
        int index;

        for(int i = 0; i < lists.size(); i++){
            if(lists[i] != nullptr){
                header_map[lists[i]->val].push(i);
                q.push(lists[i]->val);
            }else{
                not_empty_link--;
            }
        }

        while(not_empty_link || !q.empty()){
            number = q.top();
            q.pop();
            cursor->next = new ListNode(number);
            cursor = cursor->next;

            index = header_map[number].front();
            header_map[number].pop();

            lists[index] = lists[index]->next;
            if(lists[index] != nullptr){
                header_map[lists[index]->val].push(index);
                q.push(lists[index]->val);
            }else{
                not_empty_link--;
            }
        }
        return root->next;
    }
};
// @lc code=end

