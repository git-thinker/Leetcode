/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Node{
public:
    char val = ' ';
    bool end = false;
    vector<Node*> children;

    Node(){}

    Node(char val){
        this->val = val;
    }

    Node(char val, bool end){
        this->val = val;
        this->end = end;
    }

    void addNode(Node* nodeToAdd){
        this->children.push_back(nodeToAdd);
    }

};

class Trie {
public:
    Node root = Node();
    /** Initialize your data structure here. */
    Trie() {

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *proot = &this->root;
        Node *tmpNode = NULL;
        int length = word.length();
        bool flag;
        int i;

        for(i = 0; i < word.length(); ++i){
            flag = true;
            for(auto item:proot->children){
                if(item->val == word[i]){
                    flag = false;
                    proot = item;
                    length --;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if((!length) && (proot->end)){
            return ;
        }else if(!length){
            proot->end = true;
        }else{
            for(; i < word.length(); ++i){
                tmpNode = new Node(word[i], i == word.length() - 1);
                proot->addNode(tmpNode);
                proot = tmpNode;
            }
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *proot = &this->root;
        int length = word.length();
        bool flag;

        for(int i = 0; i < word.length(); ++i){
            flag = true;
            for(auto item:proot->children){
                if(item->val == word[i]){
                    flag = false;
                    proot = item;
                    length --;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        return (!length) && (proot->end);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *proot = &this->root;
        int length = prefix.length();
        bool flag;

        for(int i = 0; i < prefix.length(); ++i){
            flag = true;
            for(auto item:proot->children){
                if(item->val == prefix[i]){
                    flag = false;
                    proot = item;
                    length --;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        return !length;
    }

    bool match(string word){
        return this->recursive_match(word, &this->root);
    }

    bool recursive_match(string word, Node *startNode){
        bool flag = false;
        bool tmp = false;
        if(word.empty()){
            if(startNode->end){
                return true;
            }else{
                return false;
            }
        }else{
            if(word[0] != '.'){
                for(auto item:startNode->children){
                    if(item->val == word[0]){
                        startNode = item;
                        flag = true;
                        break;
                    }
                }
                if(flag){
                    return recursive_match(word.substr(1), startNode);
                }else{
                    return false;
                }
            }else{
                for(auto item:startNode->children){
                    tmp = recursive_match(word.substr(1), item);
                    if(tmp) break;
                }
                return tmp;
            }
        }
    }
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    Trie myTrie = Trie();
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        this->myTrie.insert(word);
    }
    
    bool search(string word) {
        return this->myTrie.match(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

