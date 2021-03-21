/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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

#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int level;
        vector<vector<int>> ret;
        queue<TreeNode*> myQueue;
        if(root) myQueue.push(root);
        else return ret;
        while(!myQueue.empty()){
            ret.push_back(vector<int>());
            level = myQueue.size();
            while(level--){
                root = myQueue.front();
                myQueue.pop();
                ret.rbegin()->push_back(root->val);
                if(root->left)myQueue.push(root->left);
                if(root->right)myQueue.push(root->right);
            }
        }
        return ret;
    }
};
// @lc code=end

