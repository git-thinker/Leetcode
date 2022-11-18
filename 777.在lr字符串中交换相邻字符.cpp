/*
 * @lc app=leetcode.cn id=777 lang=cpp
 *
 * [777] 在LR字符串中交换相邻字符
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canTransform(string start, string end) {
        if(start.size() != end.size()) return false;
        int i = 0;
        int j = 0;
        int n = start.size();
        while(i < n || j < n){
            if(i == n){
                if(end[j] != 'X') return false;
                j++;
            }else if(j == n){
                if(start[i] != 'X') return false;
                i++;
            }
            for(;start[i]=='X';i++);
            for(;end[j]=='X';j++);
            if(start[i] != end[j]) return false;
            switch(start[i]){
                case 'L': 
                    if(i < j) return false;
                    break;
                case 'R':
                    if(i > j) return false;
                    break;
            }
            i++;j++;
        }
        return true;
    }
};
// @lc code=end

