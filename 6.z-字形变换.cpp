/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include<string>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int i = 0;
        string ret;
        vector<int> index;
        // 0 for none 1 for forward 2 for backward
        while(1){
            index.push_back(i);
            i += numRows;
            if(i >= s.size()) break;

            index.push_back(i);
            i += numRows - 2;
            if(i >= s.size()) break;
        }
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < index.size(); j++){
                if(j % 2 == 0){
                    // forward index
                    if(index[j]+i < s.size())
                        ret.push_back(s[index[j]+i]);
                }else{
                    // backward index
                    if(i != 0 && i != numRows-1 && index[j]+numRows-2-i < s.size())
                        ret.push_back(s[index[j]+numRows-2-i]);
                }
            }
        }
        return ret;
    }
};
// @lc code=end

