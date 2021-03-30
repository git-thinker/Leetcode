/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<stack>
#include"ds.h"
using namespace std;
class BSTIterator {
public:
    stack<TreeNode*> myStack;
    TreeNode* cursor;   
    BSTIterator(TreeNode* root) {
        this->cursor = root;
        while(cursor){
            this->myStack.emplace(cursor);
            cursor = cursor->left;
        }
    }
    
    int next() {
        int ans;
        
        cursor = myStack.top();
        myStack.pop();
        
        
        ans = cursor->val;
        cursor = cursor->right;
        while(cursor){
            this->myStack.emplace(cursor);
            cursor = cursor->left;
        }
         
        return ans;
    }
    
    bool hasNext() {
        return(!this->myStack.empty() || cursor != nullptr);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

