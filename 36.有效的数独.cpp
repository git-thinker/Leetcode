/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
#include<vector>
#include<hash_set>
using namespace std;
using namespace __gnu_cxx;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        hash_set<char> mySet;
        int count = 0;
        for(int i = 0; i < 9; ++i){
            count = 0;mySet.clear();
            for(int j = 0; j < 9; ++j){
                if(board[i][j] != '.'){
                    mySet.insert(board[i][j]);
                    count++;
                }
            }
            if(mySet.size() != count) return false;   

            count = 0;mySet.clear();
            for(int j = 0; j < 9; ++j){
                if(board[j][i] != '.'){
                    mySet.insert(board[j][i]);
                    count++;
                }
            }
            if(mySet.size() != count) return false;
        }

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int coreX = i * 3 + 1;
                int coreY = j * 3 + 1;
                count = 0;mySet.clear();
                for(int m = -1; m <= 1; m++){
                    for(int n = -1; n <= 1; n++){
                        if(board[coreX+m][coreY+n] != '.'){
                            mySet.insert(board[coreX+m][coreY+n]);
                            count++;
                        }
                    }
                }
                if(mySet.size() != count) return false;
            }
        }

        return true;
    }
};
// @lc code=end

