/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
// #include"ds.h"
#include<vector>
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return generateSubTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

    TreeNode* generateSubTree(vector<int>& preorder, int i, int j, vector<int>& inorder, int x, int y){
        // valid zone [i,j)
        // valid zone [x,y)
        int k, z;
        if(i >= j || x >= y) return nullptr;
        TreeNode* root = new TreeNode(preorder[i]);
        for(z = x; z < y; ++z){
            if(inorder[z] == root->val)break;
        }

        // couning how many nodes is in left-subtree according to inorder
        // thus divide preorder
        k = i + z - x + 1;

        root->left = generateSubTree(preorder, i+1, k, inorder, x, z);
        root->right = generateSubTree(preorder, k, j, inorder, z+1, y);
        return root;
    }
};
// @lc code=end

