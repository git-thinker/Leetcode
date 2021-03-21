/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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

#include<queue>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // return recursive(root, root);
        TreeNode *l, *r;
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        myQueue.push(root);
        while(!myQueue.empty()){
            l = myQueue.front();
            myQueue.pop();
            r = myQueue.front();
            myQueue.pop();
            if(!l ^ !r) return false;
            if(!l && !r) continue;
            if(l->val != r->val) return false;
            myQueue.push(l->left);
            myQueue.push(r->right);
            myQueue.push(l->right);
            myQueue.push(r->left);
        }
        return true;
        
    }

    // bool recursive(TreeNode* left, TreeNode* right){
    //     if(!left && !right) return true;
    //     if(!left || !right) return false;
    //     return left->val == right->val && recursive(left->left, right->right) && recursive(left->right, right->left);
    // }

};
// @lc code=end

