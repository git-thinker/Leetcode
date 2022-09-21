/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        return recursive(n);
    }

    int recursive(int n){
        // assume there are n int to be pushed
        if(n <= 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        int ret = 0;
        for(int i = 0; i <= (n - 1) / 2; i++){
            if(n % 2 && i == (n - 1) / 2){
                ret += recursive(i) * recursive(n - 1 - i);
            }else{
                ret += recursive(i) * recursive(n - 1 - i) * 2;
            }
        }
        return ret;
    }
};
// @lc code=end

