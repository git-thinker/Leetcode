/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int m, n;
    void solve(vector<vector<char>>& board) {
        int i, j;
        this->m = board.size();
        if(!this->m) return;
        this->n = board[0].size();
        for(i = 0, j = 0; i < this->m; i++){this->dfs(board, i, j);}
        for(i = 0, j = this->n - 1; i < this->m; i++){this->dfs(board, i, j);}
        for(i = 0, j = 0; j < this->n; j++){this->dfs(board, i, j);}
        for(i = this->m - 1, j = 0; j < this->n; j++){this->dfs(board, i, j);}
        for(i = 0; i < this->m; i++){
            for(j = 0; j < this->n ; j++){
                if(board[i][j] == 'A'){
                    board[i][j] = 'O';
                }else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        return ;
    }

    void dfs(vector<vector<char>>& board, int i, int j){
        if(!(0 <= i  && i < this->m && 0 <= j  && j < this->n)){
            // filter out illegal coordinates
            return ;
        }
        if(board[i][j] == 'X'){
            return ;
        }else if(board[i][j] == 'O'){
            board[i][j] = 'A';
        }else if(board[i][j] == 'A'){
            return ;
        }

        // recursive
        this->dfs(board, i+1, j);
        this->dfs(board, i-1, j);
        this->dfs(board, i, j+1);
        this->dfs(board, i, j-1);
    }
};

// @lc code=end
