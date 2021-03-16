/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        // int degree = 1;
        // for(int i = 0; i < preorder.size(); ++i){
        //     if(i + 1 == preorder.size() || preorder[i+1] == ','){
        //         --degree;
        //         if(degree < 0 ) return false;
        //         if(preorder[i] != '#') degree += 2;
        //     }
        // }
        // return degree == 0;

        
        vector<int> myStack;
        myStack.push_back(1);
        for(int i = 0; i < preorder.size(); ++i){
            if(i + 1 == preorder.size() || preorder[i+1] == ','){
                --*(--myStack.end());
                if(!*(--myStack.end())) myStack.pop_back();
                if(preorder[i] != '#') myStack.push_back(2);
                if(myStack.empty() && i + 1 != preorder.size()) return false;
            }
        }
        return myStack.empty();   
    }
};
// @lc code=end

