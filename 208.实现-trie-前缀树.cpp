/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
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
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

