/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int combineJudge(int a, int b){
        if(a == 0) return b;
        if(b == 0) return a;
        if(a == b) return a;
        return -1;
    }

    int judge(const int &a, const int& b){
        if(a == b) return 0;
        if(a < b) return 1;
        if(a > b) return 2;
        return -1;
    }

    bool isMonotonic(vector<int>& A) {
        int ans = this->recursive(A, 0, A.size());
        if(ans == -1){
            return false;
        } else{
            return true;
        }
        
    }
    
    int recursive(vector<int>& A, int i, int j){
        // [i,j)
        if(j - i == 1) return 0;
        if(j - i == 2) return this->judge(A[i], A[j-1]);
        int m = (i + j) / 2;
        return this->combineJudge(this->combineJudge(this->recursive(A, i, m), this->recursive(A, m, j)),this->judge(A[m-1], A[m]));
    }
};
// @lc code=end




