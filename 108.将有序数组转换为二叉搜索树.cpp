/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
// #include "ds.h"
// #include<vector>
// using namespace std;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int m = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[m]);
        this->addOne(root, nums, 0, m);
        this->addOne(root, nums, m + 1, nums.size());
        return root;
    }

    void addOne(TreeNode* root, vector<int>& nums, int i, int j){
        if(i >= j) return ; 
        int m = (i + j) / 2;
        TreeNode* cursor = root;
        while(true){
            if(cursor->val > nums[m]){
                if(cursor->left) cursor = cursor->left;
                else{
                    cursor->left = new TreeNode(nums[m]);
                    break;
                }
            }else{
                if(cursor->right) cursor = cursor->right;
                else{
                    cursor->right = new TreeNode(nums[m]);
                    break;
                }
            }
        }
        this->addOne(root, nums, i, m);
        this->addOne(root, nums, m + 1, j);
    }
};
// @lc code=end

