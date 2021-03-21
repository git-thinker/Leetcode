/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        if(n < 2) return 0;
        vector<int> mySet;
        for(int i = 2; i < n; ++i){
            bool flag = true;
            for(int j : mySet){
                if(i % j == 0){
                    flag = false;   
                    break;
                }if(j > sqrt(i) + 1) break;
            }
            if(flag) mySet.emplace_back(i);
        }
        return mySet.size();
    }
};
// @lc code=end

