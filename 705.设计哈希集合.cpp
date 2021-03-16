/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] 设计哈希集合
 */

// @lc code=start
#include<vector>
#include<list>
using namespace std;

class MyHashSet {
public:
    int hashBase = 10009;
    vector<list<int>> storage = vector<list<int>>(hashBase, list<int>());
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        for(int i: this->storage[key % this->hashBase]){
            if(i == key){
                return ;
            }
        }
        this->storage[key % this->hashBase].push_back(key);
    }
    
    void remove(int key) {
        int index = key % this->hashBase;
        for(auto iter = this->storage[index].begin(); iter != this->storage[index].end(); ++iter){
            if(*iter == key){
                this->storage[index].erase(iter);
                return ;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        for(int i: this->storage[key % this->hashBase]){
            if(i == key){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

