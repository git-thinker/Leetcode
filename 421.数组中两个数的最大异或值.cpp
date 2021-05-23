/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */
#include <vector>
using namespace std;
// @lc code=start
class Node{
    public:
        Node* left;
        Node* right;

        Node(){
            this->left = nullptr;
            this->right = nullptr;
        }
};

class Trie{
    public:
        Node* root;

        Trie(){
            this->root = new Node();
        }

        void add(int num_){
            unsigned int num = num_;
            bool bit;
            Node* cursor = root;
            for(int i = 0; i < 32; i++){
                bit = num & 0x80000000;
                num <<= 1;
                if(bit == 0){
                    if(!cursor->left){
                        cursor->left = new Node();
                    }
                    cursor = cursor->left;
                }else{
                    if(!cursor->right){
                        cursor->right = new Node();
                    }
                    cursor = cursor->right;
                }
            }
        }

        int get(int op_num_){
            int ret = 0;
            bool tmp;
            unsigned int op_num = op_num_;
            Node* cursor = root;
            for(int i = 0; i < 32; i++){
                tmp = op_num & 0x80000000;
                op_num <<= 1;
                if(!tmp){
                    if(cursor->right){
                        cursor = cursor->right;
                        ret += 1;
                    }
                    else{
                        cursor = cursor->left;
                    }
                }else{
                    if(cursor->left){
                        cursor = cursor->left;
                        ret += 1;
                    }
                    else{
                        cursor = cursor->right;
                    }
                }
                if(i != 31) ret <<=1;
            }
            return ret;
        }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie myTrie = Trie();
        int ret = -2147483647;
        for(int num:nums){
            myTrie.add(num);
        }
        for(int num:nums){
            int tmp = myTrie.get(num);
            if(tmp > ret) ret = tmp;
        }
        return ret;
    }
};
// @lc code=end

