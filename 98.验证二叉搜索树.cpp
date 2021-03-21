/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
// #include<stack>
// using namespace std;
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
    bool isValidBST(TreeNode* root) {
        int lastVal;
        bool flag = true;
        stack<TreeNode*> myStack;
        if(root == nullptr) return false;
        do{
            while(root){
                myStack.push(root);
                root = root->left;
            }
            root = myStack.top();
            myStack.pop();

            // visit
            if(flag) {
                lastVal = root->val;
                flag = false;
            }
            else if(lastVal >= root->val) return false;
            lastVal = root->val;

            root = root->right;            
        }while(!myStack.empty() || root != nullptr);
        return true;
    }
};
// @lc code=end

