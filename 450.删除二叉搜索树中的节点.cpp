/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;
        if(root->val > key){
            root->left = deleteNode(root->left, key);
        }else if(root->val < key){
            root->right = deleteNode(root->right, key);
        }else{
            if(root->left == nullptr && root->right == nullptr) return nullptr;
            else if(root->left != nullptr && root->right == nullptr) return root->left;
            else if(root->left == nullptr && root->right != nullptr) return root->right;
            else{
                TreeNode* proot = root->right;
                while(proot->left){
                    proot = proot->left;
                }
                root->val = proot->val;
                root->right = deleteNode(root->right, proot->val);
            }
        }
        return root;
    }
};
// @lc code=end

