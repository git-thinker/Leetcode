/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] 设计哈希映射
 */

// @lc code=start
#include<vector>
#include<list>
#include<map>
using namespace std;
class MyHashMap {
public:
    int hashBase = 10009;
    vector<list<pair<int, int>>> storage = vector<list<pair<int, int>>>(hashBase, list<pair<int, int>>());
    /** Initialize your data structure here. */
    MyHashMap() {

    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = key % this->hashBase;
        for(auto &thisPair: this->storage[index]){
            if(thisPair.first == key){
                thisPair.second = value;
                return ;
            }
        }
        this->storage[index].push_back(pair<int, int>(key, value));
        return ;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = key % this->hashBase;
        for(auto thisPair: this->storage[index]){
            if(thisPair.first == key){
                return thisPair.second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = key % this->hashBase;
        for(auto iter = this->storage[index].begin(); iter != this->storage[index].end(); iter++){
            if(iter->first == key){
                this->storage[index].erase(iter);
                return ;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

