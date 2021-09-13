/*
 * @lc app=leetcode.cn id=1894 lang=cpp
 *
 * [1894] 找到需要补充粉笔的学生编号
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long s = 0;
        int i = 0;
        for(auto item: chalk){
            s += item;
        }
        k %= s;
        for(i = 0; i < chalk.size(); i++){
            if(chalk[i] > k) break;
            else k -= chalk[i];
        }
        return i;
    }
};
// @lc code=end

