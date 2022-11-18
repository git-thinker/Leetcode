/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class LinkNode{
private:
    int val;
    LinkNode* pNext;
    LinkNode* pPrev;
    void setNext(LinkNode* next){
        this->pNext = next;
    }

    void setPrev(LinkNode* prev){
        this->pPrev = prev;
    }

public:
    LinkNode(int val){
        this->val = val;
        this->pPrev = nullptr;
        this->pNext = nullptr;
    }
    

    LinkNode* getNext(){
        return this->pNext;
    }

    LinkNode* getPrev(){
        return this->pPrev;
    }

    int getVal(){
        return this->val;
    }

    void joinAsHead(LinkNode* tail){
        this->setNext(tail);
        if(tail != nullptr){
            tail->setPrev(this);
        }
    }
};

class MyLinkedList {
private:
    LinkNode* head;
    LinkNode* tail;
    int len;
public:
    MyLinkedList() {
        this->head = new LinkNode(-1);
        this->tail = new LinkNode(-1);
        this->head->joinAsHead(this->tail);
        this->len = 0;
    }
    
    int get(int index) {
        LinkNode* ptr = this->head;
        for(int i = 0; i <= index; i++){
            if(ptr == nullptr) break;
            ptr = ptr->getNext();
        }
        if(ptr == nullptr) return -1;
        return ptr->getVal();
    }
    
    void addAtHead(int val) {
        LinkNode* head = this->head;
        LinkNode* ptr = new LinkNode(val);
        LinkNode* tail = this->head->getNext();
        head->joinAsHead(ptr);
        ptr->joinAsHead(tail);
        this->len++;
    }
    
    void addAtTail(int val) {
        LinkNode* head = this->tail->getPrev();
        LinkNode* ptr = new LinkNode(val);
        LinkNode* tail = this->tail;
        head->joinAsHead(ptr);
        ptr->joinAsHead(tail);
        this->len++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > this->len) return;
        if(index < 0) index = 0;
        LinkNode* head = this->head;
        LinkNode* ptr = new LinkNode(val);
        LinkNode* tail;
        for(int i = 0; i < index; i++){
            head = head->getNext();
        }
        tail = head->getNext();
        head->joinAsHead(ptr);
        ptr->joinAsHead(tail);
        this->len++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= this->len) return;
        LinkNode* ptr = this->head;
        for(int i = 0; i <= index; i++){
            ptr = ptr->getNext();
        }
        LinkNode* head = ptr->getPrev();
        LinkNode* tail = ptr->getNext();
        head->joinAsHead(tail);
        this->len--;
        delete ptr;
    }
};
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

