/*
 * @lc app=leetcode.cn id=1652 lang=cpp
 *
 * [1652] 拆炸弹
 */
#include<vector>
#include<numeric>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if(k == 0){
            return vector<int>(code.size(), 0);
        }
        int tmp;
        int i, j;
        if(k > 0){
            i = 1;
            j = 1 + k;
            tmp = accumulate(code.begin()+1, code.begin()+k+1, 0);
        }else if(k < 0){
            i = code.size() + k;
            j = code.size();
            tmp = accumulate(code.end()+k, code.end(), 0);
        }
        vector<int> ret = {tmp};
        while(ret.size() != code.size()){
            if(i < 0 || i >= code.size()){
                i += code.size();
                i %= code.size();
            }
            if(j < 0 || j >= code.size()){
                j += code.size();
                j %= code.size();
            }
            tmp -= code[i];
            tmp += code[j];
            ret.push_back(tmp);
            i++;
            j++;
        }
        return ret;
    }
};
// @lc code=end

