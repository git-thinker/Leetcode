/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
#include"ds.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int layer = 0;
        int size;
        queue<TreeNode*> toVisit;
        deque<int> myDeque;
        vector<vector<int>> ret;
        if(!root) return ret;
        toVisit.push(root);
        while(!toVisit.empty()){
            size = toVisit.size();
            layer++;
            while(size--){
                myDeque.push_back(toVisit.front()->val);
                if(toVisit.front()->left)toVisit.push(toVisit.front()->left);
                if(toVisit.front()->right)toVisit.push(toVisit.front()->right);
                toVisit.pop();
            }
            vector<int> tmp;
            while(!myDeque.empty()){
                if(layer % 2){
                    tmp.push_back(myDeque.front());
                    myDeque.pop_front();
                }else{
                    tmp.push_back(myDeque.back());
                    myDeque.pop_back();
                }
            }
            
            ret.emplace_back(tmp);
        }
        return ret;
    }
};
// @lc code=end

