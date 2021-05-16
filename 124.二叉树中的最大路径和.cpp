/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */
#include "ds.h"
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
class Solution {
public:
    int maxmium = -2147483647;
    int maxPathSum(TreeNode* root) {
        recursive(root);
        return maxmium;
    }

    int recursive(TreeNode* proot){
        if(!proot) return 0;
        int left = recursive(proot->left);
        int right = recursive(proot->right);
        if(proot->val > maxmium){
            maxmium = proot->val;
        }
        if(proot->val + left + right > maxmium){
            maxmium = proot->val + left + right;
        }
        if(proot->val + right > maxmium){
            maxmium = proot->val + right;
        }
        if(proot->val + left > maxmium){
            maxmium = proot->val + left;
        }
        if(left < 0 && right < 0) return proot->val;
        if(left > right) return left + proot->val;
        else return right + proot->val;
    }
};
// @lc code=end

