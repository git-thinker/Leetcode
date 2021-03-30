/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool flag = false;
    int m, n;
    bool exist(vector<vector<char>>& board, string word) {
        flag = false;
        m = board.size();
        n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                check(board, i, j, 0, word);
                if(flag) return true;
            }
        }
        return false;
    }

    void check(vector<vector<char>>& board, int i, int j, int index, string& word){
        if(index == word.size()){
            flag = true;
            return ;
        }
        if(i < 0 || j < 0 || i >= m || j >= n || flag) return;
        if(board[i][j] == word[index]){
            board[i][j] = '#';
            check(board, i-1, j, index+1, word);
            check(board, i+1, j, index+1, word);
            check(board, i, j-1, index+1, word);
            check(board, i, j+1, index+1, word);
            board[i][j] = word[index];
        }
    }

};
// @lc code=end

