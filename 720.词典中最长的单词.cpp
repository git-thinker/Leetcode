/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 */

// @lc code=start
# include<vector>
# include<string>
# include<algorithm>
using namespace std;

class Node;
bool NodeComp(const Node *n1, const Node *n2);

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
        sort(this->children.begin(), this->children.end(), NodeComp);
    }

};

bool NodeComp(const Node *n1, const Node *n2){
    if(n1->val < n2->val){
        return true;
    }
    return false;
}



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

class Solution {
public:
    void dfs(Node* cursor, string &tmp, string &rst){
        if(cursor->val != ' '){
            if(cursor->end){
                tmp += cursor->val;
                if(tmp.length() > rst.length()){
                    rst = tmp;
                }
                for(auto nextCursor:cursor->children){
                    dfs(nextCursor, tmp, rst);
                }
                tmp.pop_back();
            }else{
                return ;
            }
        }else{
            for(auto nextCursor:cursor->children){
                    dfs(nextCursor, tmp, rst);
            }
        }
    }

    string longestWord(vector<string>& words) {
        Trie myTrie = Trie();
        Node* cursor;
        string rst = "";
        string tmp = "";
        for(auto str:words){
            myTrie.insert(str);
        }
        dfs(&myTrie.root, tmp, rst);
        return rst;
    }
};
// @lc code=end

