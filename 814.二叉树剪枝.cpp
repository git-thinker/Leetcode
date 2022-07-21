/*
 * @lc app=leetcode.cn id=814 lang=cpp
 *
 * [814] 二叉树剪枝
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
    TreeNode* pruneTree(TreeNode* root) {
        TreeNode* new_root = new TreeNode();
        new_root->left = root;
        recursive(new_root);
        return new_root->left;
    }

    bool recursive(TreeNode* ptr){
        if(ptr == nullptr){
            return true;
        }
        bool left = recursive(ptr->left);
        bool right = recursive(ptr->right);
        if(left){
            ptr->left = nullptr;
        }
        if(right){
            ptr->right = nullptr;
        }
        if(left && right && ptr->val==0){
            return true;
        }else{
            return false;
        }
    }
};
// @lc code=end

