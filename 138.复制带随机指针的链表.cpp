/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */


#include<map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
// @lc code=start

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cursorOld;
        Node* cursorNew;
        Node* headNew = new Node(0);
        map<Node*, Node*> myMap;
        // copy value
        cursorNew = headNew;
        cursorOld = head;
        while(cursorOld != nullptr){
            cursorNew->next = new Node(cursorOld->val);
            cursorNew = cursorNew->next;
            myMap[cursorOld] = cursorNew;
            cursorOld = cursorOld->next;
        }

        // loading address
        cursorNew = headNew->next;
        cursorOld = head;
        while(cursorOld != nullptr){
            cursorNew->random = myMap[cursorOld->random];
            cursorNew = cursorNew->next;
            cursorOld = cursorOld->next;
        }
        return headNew->next;
    }
};
// @lc code=end

